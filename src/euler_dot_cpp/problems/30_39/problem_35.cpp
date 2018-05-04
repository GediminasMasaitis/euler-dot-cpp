#include "stdafx.hpp"
#include "problem_35.hpp"
#include "../../common/digits.hpp"
#include "../../common/primes.hpp"

using namespace std;

template<typename TValue>
constexpr void get_rotations(TValue num, const size_t digit_count, alg_idx_res_pred<size_t, TValue> pred, const int32_t base = 10)
{
    TValue mul = 1;
    for (auto i = 1; i < digit_count; ++i)
    {
        mul *= base;
    }

    for (auto i = 0; i < digit_count; ++i)
    {
        if (!pred(i, num))
        {
            return;
        }
        num = (num / base) + ((num%base)*mul);
    }
}

int64_t impl_35_1::solve()
{
    constexpr int64_t limit = 1000000;

    auto is_prime = get_prime_sieve(limit);
    int64_t count = 0;
    for(auto i = 2; i < limit; ++i)
    {
        const auto digit_count = get_digit_count(i);
        auto success = true;
        get_rotations<int64_t>(i, digit_count, [&success, &is_prime](size_t, const int64_t rot)
        {
            if(!is_prime[rot])
            {
                success = false;
                return false;
            }
            return true;
        });
        if(success)
        {
            ++count;
        }
    }
    return count;
}