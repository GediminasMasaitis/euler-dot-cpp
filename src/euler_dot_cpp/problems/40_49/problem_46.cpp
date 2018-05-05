#include "stdafx.hpp"
#include "problem_46.hpp"
#include "../../common/primes.hpp"

using namespace std;

int64_t impl_46_1::solve()
{
    uint64_t result = 0;
    for (auto i = 5;; i += 2)
    {
        bool success = true;
        segmented_sieve<uint64_t, uint64_t>(i, [i, &success](int64_t idx, int64_t prime)
        {
            uint64_t num = 0;
            for (uint64_t j = 0; num < i; ++j)
            {
                num = prime + 2 * j*j;
                if (num == i)
                {
                    success = false;
                    return false;
                }
            }
            return true;
        });
        if(success)
        {
            return i;
        }
    }
    return -1;
}