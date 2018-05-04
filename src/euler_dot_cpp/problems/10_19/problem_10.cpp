#include "stdafx.hpp"
#include "problem_10.hpp"

#include "../../common/primes.hpp"

using namespace std;

int64_t impl_10_1::solve()
{
    uint64_t sum = 0;
    auto primes = get_segmented_sieve<uint64_t>(2000000ULL);
    for (auto i = 0; i < primes.size(); i++)
    {
        sum += primes[i];
    }
    return sum;
}

int64_t impl_10_2::solve()
{
    uint64_t sum = 0;
    segmented_sieve<uint64_t, uint64_t>(2000000ULL, [&sum](uint64_t, uint64_t prime)
    {
        sum += prime;
        return true;
    });
    return sum;
}
