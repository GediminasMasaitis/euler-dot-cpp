#include "stdafx.hpp"
#include "problem_23.hpp"

#include "../../common/factors.hpp"

#include <numeric>

using namespace std;

int64_t impl_23_1::solve()
{
    vector<uint64_t> abundants;
    constexpr uint64_t limit = 28123;
    for (uint64_t i = 1; i <= limit; ++i)
    {
        auto divisors = get_proper_divisors(i);
        const auto sum = std::accumulate(divisors.begin(), divisors.end(), 0ULL);
        if(sum > i)
        {
            abundants.push_back(i);
        }
    }

    vector<char> sieve;
    sieve.resize(limit, 1);

    for (auto i = 0; i < abundants.size(); i++)
    {
        for (auto j = i; j < abundants.size(); j++)
        {
            const auto sum = abundants[i] + abundants[j];
            if(sum < sieve.size())
            {
                sieve[sum] = false;
            }
        }
    }

    uint64_t total = 0;
    for (auto i = 0; i <= sieve.size(); i++)
    {
        if(sieve[i])
        {
            total += i;
        }
    }

    return total;
}