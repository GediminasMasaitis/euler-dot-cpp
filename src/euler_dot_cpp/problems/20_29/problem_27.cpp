#include "stdafx.hpp"
#include "problem_27.hpp"

#include "../../common/primes.hpp"

using namespace std;

int64_t impl_27_1::solve()
{
    constexpr uint64_t prime_limit = 2000000; // shoud be enough
    auto is_prime_ptr = make_unique<array<char, prime_limit>>();
    auto& is_prime = *is_prime_ptr;
    fill(is_prime.begin(), is_prime.end(), false);
    segmented_sieve<uint64_t, uint64_t>(prime_limit, [&is_prime](uint64_t, const uint64_t prime)
    {
        is_prime[prime] = true;
        return true;
    });

    uint64_t max_n = 0;
    int64_t result = 0;

    for(int64_t a = -999; a <= 999; a++)
    {
        for (int64_t b = -999; b <= 999; b++)
        {
            int64_t n = 0;
            for (;;++n)
            {
                const int64_t candidate = n * n + a * n + b;
                if (candidate < 0 || candidate >= prime_limit || !is_prime[candidate])
                {
                    break;
                }
            }
            if(n > max_n)
            {
                max_n = n;
                result = a * b;
            }
        }
    }
	return result;
}

int64_t impl_27_2::solve()
{
    uint64_t max_n = 0;
    int64_t result = 0;

    for (int64_t a = -999; a <= 999; a++)
    {
        for (int64_t b = -999; b <= 999; b++)
        {
            uint64_t n = 0;
            for (;;++n)
            {
                const int64_t candidate = n * n + a * n + b;
                if (candidate < 0 || !boost::multiprecision::miller_rabin_test(candidate, 5))
                {
                    break;
                }
            }
            if (n > max_n)
            {
                max_n = n;
                result = a * b;
            }
        }
    }
    return result;
}
