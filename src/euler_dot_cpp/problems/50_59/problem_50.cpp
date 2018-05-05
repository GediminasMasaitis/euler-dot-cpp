#include "stdafx.hpp"
#include "problem_50.hpp"
#include "../../common/primes.hpp"

using namespace std;

int64_t impl_50_1::solve()
{
    constexpr uint64_t limit = 1000000;
    auto primes = get_segmented_sieve(limit);
    int64_t max_count = 0;
    int64_t max_prime = 0;
    for (auto i = 0; i < primes.size(); ++i)
    {
        const auto prime = primes[i];
        int64_t len = 0;
        int64_t sum = 0;
        for (auto j = 0; j < i; ++j)
        {
            sum += primes[j];
            len++;
            while (sum > prime)
            {
                --len;
                sum -= primes[j - len];
            }
            if (sum == prime && len > max_count)
            {
                max_count = len;
                max_prime = prime;
            }
        }
    }
    return max_prime;
}

int64_t impl_50_2::solve()
{
    constexpr uint64_t limit = 1000000;
    auto primes = get_segmented_sieve(limit);
    int64_t max_count = 0;
    int64_t max_prime = 0;
    for(auto i = 0; i < primes.size(); ++i)
    {
        const auto prime = primes[i];
        for (auto j = 0; j < i; ++j)
        {
            auto sum = 0;
            for(auto k = 0; k < i; ++k)
            {
                sum += primes[j + k];
                if(sum == prime)
                {
                    if(k > max_count)
                    {
                        max_count = k;
                        max_prime = prime;
                    }
                    break;
                }
                if(sum > prime)
                {
                    break;
                }
            }
        }
    }
    return max_prime;
}