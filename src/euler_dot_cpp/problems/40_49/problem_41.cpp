#include "stdafx.hpp"
#include "problem_41.hpp"
#include "../../common/primes.hpp"

using namespace std;

int64_t impl_41_1::solve()
{
    constexpr int64_t limit = 100000000;
    auto is_prime = get_prime_sieve(limit);
    std::mt19937 rng(0);
    const auto success = boost::multiprecision::miller_rabin_test(123, 4, rng);
   
	return 0;
}