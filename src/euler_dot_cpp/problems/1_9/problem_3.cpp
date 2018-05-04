#include "stdafx.hpp"
#include "problem_3.hpp"

#include "../../common/factors.hpp"

using namespace std;

int64_t impl_3_1::solve()
{
	auto results = get_prime_factors(600851475143LL);
	const auto max = *std::max_element(results.begin(), results.end());
	return max;
}

int64_t impl_3_2::solve()
{
    int64_t max = 0;
    prime_factors<int64_t, int64_t>(600851475143LL, [&max](int64_t factor)
    {
        if(factor > max)
        {
            max = factor;
        }
    });
    return max;
}
