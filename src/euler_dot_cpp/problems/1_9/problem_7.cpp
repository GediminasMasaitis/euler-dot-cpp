#include "stdafx.hpp"
#include "problem_7.hpp"

#include "../../common/primes.hpp"

using namespace std;

static vector<uint64_t> get_n_primes(int prime_index)
{
    vector<uint64_t> primes;
    primes.reserve(prime_index);
    primes.push_back(2);
    for(auto i = 3; primes.size() < prime_index; i += 2)
    {
        auto success = true;
        for(auto& prime : primes)
        {
            if(i % prime == 0)
            {
                success = false;
                break;
            }
        }
        if(success)
        {
            primes.push_back(i);
        }
    }
    return primes;
}

static vector<uint64_t> get_primes_sieve(const int limit)
{
    vector<uint64_t> primes;
    vector<bool> sieve;
    //primes.reserve(limit
    const auto incto = static_cast<int>(ceil(sqrt(limit)));
    sieve.resize(limit, true);
    for (auto inc = 2; inc < incto;)
    {
        //primes.push_back()
        for(auto j = inc*2; j < limit; j += inc)
        {
            sieve[j] = false;
        }
        inc++;
        while (!sieve[inc])
        {
            inc++;
        }
    }
    for (auto i = 2; i < limit; i++)
    {
        if(sieve[i])
        {
            primes.push_back(i);
        }
    }
    return primes;
}




int64_t impl_7_1::solve()
{
    auto primes = get_n_primes(10001);
    return primes.back();
}

int64_t impl_7_2::solve()
{
    auto primes = get_primes_sieve(200000);
    return primes[10000];
}

int64_t impl_7_3::solve()
{
    auto primes = get_segmented_sieve(200000ULL);
    return primes[10000];
}