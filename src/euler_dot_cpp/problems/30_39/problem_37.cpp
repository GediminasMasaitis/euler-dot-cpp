#include "stdafx.hpp"
#include "problem_37.hpp"
#include "../../common/primes.hpp"
#include "../../common/digits.hpp"

using namespace std;

template<typename TValue>
constexpr TValue truncate_right(const TValue num, const int32_t base = 10)
{
    return num / base;
}

template<typename TValue>
constexpr TValue truncate_left(const TValue num, const int32_t base = 10)
{
    auto len = get_digit_count(num, base);
    TValue div = 1;
    for(size_t i = 0; i < len-1; i++)
    {
        div *= base;
    }
    return num % div;
}

template<typename TValue>
bool is_left_truncatable_prime(std::vector<uint8_t>& is_prime, TValue num, const int32_t base = 10)
{
    auto len = get_digit_count(num, base);
    TValue div = 1;
    for (size_t i = 0; i < len - 1; i++)
    {
        div *= base;
    }

    while(num != 0)
    {
        if(!is_prime[num])
        {
            return false;
        }
        num %= div;
        div /= base;
    }    
    return true;
}

template<typename TValue>
bool is_left_truncatable_prime2(std::mt19937 rng, TValue num, const int32_t base = 10)
{
    auto len = get_digit_count(num, base);
    TValue div = 1;
    for (size_t i = 0; i < len - 1; i++)
    {
        div *= base;
    }

    while (num != 0)
    {
        if (!boost::multiprecision::miller_rabin_test(num, 5, rng))
        {
            return false;
        }
        num %= div;
        div /= base;
    }
    return true;
}

int64_t impl_37_1::solve()
{
    int64_t sum = 0;
    constexpr auto limit = 1000000;
    auto is_prime = get_prime_sieve(limit);

    for(auto i = 10; i < limit; ++i)
    {
        auto success = true;

        // right
        auto num = i;
        while(num != 0)
        {
            if(!is_prime[num])
            {
                success = false;
                break;
            }
            num = truncate_right(num);
        }
        if(!success)
        {
            continue;
        }

        // left
        num = i;
        while (num != 0)
        {
            if (!is_prime[num])
            {
                success = false;
                break;
            }
            num = truncate_left(num);
        }
        if (!success)
        {
            continue;
        }
        sum += i;
    }

	return sum;
}

int64_t impl_37_2::solve()
{
    int64_t sum = 0;
    constexpr auto limit = 1000000;
    auto is_prime = get_prime_sieve(limit);
    vector<int64_t> rtr_primes{ 2,3,5,7 };

    for(auto i = 0; i < rtr_primes.size(); ++i)
    {
        const auto prime_mul = rtr_primes[i]*10;
        for(auto j = 1; j <= 9; ++j)
        {
            auto candidate = prime_mul + j;
            if(candidate < limit && is_prime[candidate])
            {
                rtr_primes.push_back(candidate);
            }
        }
    }

    for(auto i = 4; i < rtr_primes.size(); ++i)
    {
        const auto num = rtr_primes[i];
        const auto success = is_left_truncatable_prime(is_prime, num);
        if (success)
        {
            sum += rtr_primes[i];
        }
    }

    return sum;
}

int64_t impl_37_3::solve()
{
    int64_t sum = 0;
    mt19937 rng(0);
    vector<int64_t> rtr_primes{ 2,3,5,7 };

    for (auto i = 0; i < rtr_primes.size(); ++i)
    {
        const auto prime_mul = rtr_primes[i] * 10;
        for (auto j = 1; j <= 9; ++j)
        {
            auto candidate = prime_mul + j;
            if (boost::multiprecision::miller_rabin_test(candidate, 5, rng))
            {
                rtr_primes.push_back(candidate);
            }
        }
    }

    for (auto i = 4; i < rtr_primes.size(); ++i)
    {
        const auto num = rtr_primes[i];
        const auto success = is_left_truncatable_prime2(rng, num);
        if (success)
        {
            sum += rtr_primes[i];
        }
    }

    return sum;
}
