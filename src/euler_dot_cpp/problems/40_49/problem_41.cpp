#include "stdafx.hpp"
#include "problem_41.hpp"
#include "../../common/primes.hpp"

using namespace std;

int64_t impl_41_1::solve()
{
    auto rng = mt19937(0);
    int64_t start = 123456789;
    while(start != 1)
    {
        auto lo = to_string(start);
        auto hi = lo;
        reverse(hi.begin(), hi.end());
        while(hi != lo)
        {
            auto num = stoll(hi);
            if (boost::multiprecision::miller_rabin_test(num, 5, rng))
            {
                return num;
            }
            prev_permutation(hi.begin(), hi.end());
        }
        start /= 10;
    }
	return -1;
}