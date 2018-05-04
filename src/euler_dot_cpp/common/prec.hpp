#pragma once

class big_int
{
public:
    using data_t = uint64_t;

    //std::array<data_t, 10> buckets = {};
    std::vector<data_t> buckets;

    static constexpr data_t zero() { return static_cast<data_t>(0); }
    static constexpr size_t get_data_size() { return sizeof(data_t)*8; }
    static constexpr size_t get_half_size() { return get_data_size()/2; }
    static constexpr data_t get_mask() { return ~static_cast<data_t>(0); }
    static constexpr data_t get_mask_lo() { return get_mask() >> get_half_size(); }
    static constexpr data_t get_mask_hi() { return get_mask_lo() << get_half_size(); }

    void ensure_size(const size_t capacity)
    {
        const auto parts = (capacity + sizeof(data_t) - 1) / sizeof(data_t);
        if(parts > buckets.size())
        {
            buckets.resize(parts, static_cast<data_t>(0));
        }
    }

    size_t size() const
    {
        return buckets.size() * sizeof(data_t);
    }

    void shrink(size_t keep_min = 1)
    {
        /*auto cnt = 0;
        auto last_it = buckets.rend()-1;
        for(auto it = buckets.rbegin(); it != last_it; ++it)
        {
            if(*it != zero())
            {
                break;
            }
            cnt++;
        }
        buckets.erase()*/
        while(buckets.size() > keep_min && buckets.back() == 0)
        {
            buckets.pop_back();
        }
    }

    big_int()
    {
        ensure_size(1);
        //buckets.resize(1, static_cast<data_t>(0));
        //std::fill(buckets.begin(), buckets.end(), 0);
    }

    big_int(uint8_t num)
    {
        ensure_size(sizeof(num));
        buckets[0] = num;
    }
    
    big_int(uint32_t num)
    {
        ensure_size(sizeof(num));
        constexpr auto parts = (sizeof(uint32_t) + sizeof(data_t) - 1) / sizeof(data_t);
        for(auto i = 0; i < parts; i++)
        {
            buckets[i] = num >> (i*get_data_size());
        }
        
    }

    explicit big_int(const std::string& str, int base = 16)
    {
        ensure_size(1);
        //for(auto it = str.rbegin(); it != str.rend(); ++it)
        for (auto it = str.begin(); it != str.end(); ++it)
        {
            *this *= static_cast<uint8_t>(10);
            auto num = static_cast<uint8_t>(*it - 0x30);
            *this += num;
        }
    }

    big_int& operator +=(const big_int& rhs)
    {
        const auto new_size = std::max(size(), rhs.size()) + 1;
        ensure_size(new_size);
        auto carry = 0;
        for(size_t i = 0; i < buckets.size(); i++)
        {
            auto next_carry = 0;
            auto& lhs_part = buckets[i];
            const auto rhs_part = i < rhs.buckets.size() ? rhs.buckets[i] : zero();

            if(rhs_part > get_mask() - lhs_part) // overflow
            {
                next_carry++;
            }
            lhs_part += rhs_part;
            if(carry > get_mask() - lhs_part)
            {
                next_carry++;
            }
            lhs_part += carry;
            carry = next_carry;
        }
        //shrink();
        return *this;
    }

    static data_t mul_high(const data_t& lhs, const data_t& rhs)
    {
        constexpr auto mask = get_mask_lo();
        constexpr auto shiftby = get_half_size();

        const data_t lhs_hi = lhs >> shiftby;
        const data_t lhs_lo = lhs & mask;
        const data_t rhs_lo = rhs & mask;
        const data_t rhs_hi = rhs >> shiftby;

        const data_t lhs_hi_rhs_hi = lhs_hi * rhs_hi;
        const data_t lhs_hi_rhs_lo = lhs_hi * rhs_lo;
        const data_t lhs_lo_rhs_hi = lhs_lo * rhs_hi;
        const data_t lhs_lo_rhs_lo = lhs_lo * rhs_lo;

        const data_t carry_bit = ((lhs_hi_rhs_lo & mask) + (lhs_lo_rhs_hi & mask) + (lhs_lo_rhs_lo >> shiftby)) >> shiftby;

        const data_t prod_hi = lhs_hi_rhs_hi + (lhs_hi_rhs_lo >> shiftby) + (lhs_lo_rhs_hi >> shiftby) + carry_bit;
        return prod_hi;
    }

    big_int& operator *=(const big_int& rhs)
    {
        constexpr auto max = get_mask();
        big_int product;
        product.ensure_size(size() + rhs.size());
        for(auto i = 0; i < buckets.size(); i++)
        {
            const data_t lhs_part = buckets[i];
            big_int sum;
            sum.ensure_size(product.size());
            data_t carry = 0;
            for(auto j = 0; j < rhs.buckets.size(); j++)
            {
                const data_t rhs_part = rhs.buckets[j];
                auto& bucket = sum.buckets[j];
                bucket = lhs_part * rhs_part;
                auto next_carry = mul_high(lhs_part, rhs_part); // high is carry
                if(carry > max - bucket)
                {
                    next_carry++;
                }
                bucket += carry;
                carry = next_carry;
            }
            sum.buckets[rhs.buckets.size()] = carry;
            sum <<= i*get_data_size();
            product += sum;
        }
        product.shrink();
        //buckets = std::move(product.buckets);
        *this = std::move(product);
        return *this;
    }

    big_int& operator <<=(const size_t size)
    {
        if(size == 0)
        {
            return *this;
        }
        if(size % get_data_size() != 0)
        {
            throw "later";
        }
        const auto move_by = size / get_data_size();
        for(auto i = static_cast<int32_t>(buckets.size() - move_by - 1); i >= 0; --i)
        {
            buckets[i + move_by] = buckets[i];
        }
        for(auto i = 0; i < move_by; i++)
        {
            buckets[i] = 0;
        }
        return *this;
    }

    friend big_int operator <<(big_int lhs, const size_t size)
    {
        lhs <<= size;
        return lhs;
    }

    friend big_int operator *(big_int lhs, const big_int& rhs)
    {
        lhs *= rhs;
        return lhs;
    }

    friend big_int operator +(big_int lhs, const big_int& rhs)
    {
        lhs += rhs;
        return lhs;
    }
};