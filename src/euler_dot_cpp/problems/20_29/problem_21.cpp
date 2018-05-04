#include "stdafx.hpp"
#include "problem_21.hpp"

#include "../../common/factors.hpp"

using namespace std;

int64_t impl_21_1::solve()
{
    constexpr auto max = 10000;
    vector<uint64_t> cache;
    cache.resize(max, 0);
    uint64_t total = 0;
    for (uint64_t i = 1; i < max ; ++i)
    {
        auto sum = 1;
        const auto lim = static_cast<uint64_t>(sqrt(i));
        for (uint64_t j = 2; j <= lim; ++j)
        {
            if (i % j == 0)
            {
                sum += j;
                const auto div = i / j;
                if(div != j)
                {
                    sum += div;
                }
            }
        }
        if(sum < max)
        {
            if(cache[sum] == i)
            {
                total += i + sum;
            }
            cache[i] = sum;
        }
    }
	return total;
}

int64_t impl_21_2::solve()
{
    constexpr auto max = 10000;
    vector<uint64_t> cache;
    cache.resize(max, 0);
    uint64_t total = 0;
    for (uint64_t i = 1; i < max; ++i)
    {
        auto divisors = get_proper_divisors(i);
        const auto sum = accumulate(divisors.begin(), divisors.end(), 0ULL);
        
        if (sum < max)
        {
            if (cache[sum] == i)
            {
                total += i + sum;
            }
            cache[i] = sum;
        }
    }
    return total;
}

int64_t impl_21_3::solve()
{
    constexpr auto max = 10000;
    vector<uint64_t> cache;
    cache.resize(max, 0);
    uint64_t total = 0;
    for (uint64_t i = 1; i < max; ++i)
    {
        uint64_t sum = 0;
        proper_divisors<uint64_t, uint64_t>(i, [&sum](uint64_t divisor) { sum += divisor; });

        if (sum < max)
        {
            if (cache[sum] == i)
            {
                total += i + sum;
            }
            cache[i] = sum;
        }
    }
    return total;
}
