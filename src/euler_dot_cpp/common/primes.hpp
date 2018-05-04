#pragma once
#include "alg_common.hpp"

template<typename TValue>
std::vector<uint8_t> get_prime_sieve(const TValue num)
{
    std::vector<uint8_t> sieve;
    sieve.resize(num + 1, true);
    sieve[0] = false;
    sieve[1] = false;
    for (int p = 2; p*p <= num; p++)
    {
        if (sieve[p] == true)
        {
            for (int i = p * 2; i <= num; i += p)
            {
                sieve[i] = false;
            }
        }
    }

    return sieve;
}

template<typename TValue>
std::vector<TValue> get_prime_sieve_results(const TValue num)
{
    std::vector<TValue> primes;
    auto sieve = get_prime_sieve(num);
    for (TValue p = 2; p <= num; ++p)
    {
        if (sieve[p])
        {
            primes.emplace_back(p);
        }
    }
    return primes;
}

template<typename TIndex, typename TNum>
void segmented_sieve(const TNum limit, alg_idx_res_pred<TIndex, TNum> act)
{
    const uint64_t L1D_CACHE_SIZE = 32768;

    const auto limit_sqrt = static_cast<TNum>(std::sqrt(limit));
    const auto segment_size = std::max(limit_sqrt, L1D_CACHE_SIZE);
    //uint64_t count = (limit < 2) ? 0 : 1;

    // we sieve primes >= 3
    TNum i = 3;
    TNum n = 3;
    TNum s = 3;

    std::vector<char> sieve(segment_size);
    std::vector<char> is_prime(limit_sqrt + 1, true);
    std::vector<TNum> primes;
    if(!act(0, 2))
    {
        return;
    }
    TIndex all_index = 1;
    std::vector<TNum> multiples;

    for (TNum low = 0; low <= limit; low += segment_size)
    {
        std::fill(sieve.begin(), sieve.end(), true);

        auto high = low + segment_size - 1;
        high = std::min(high, limit);

        // generate sieving primes using simple sieve of Eratosthenes
        for (; i * i <= high; i += 2)
        {
            if (is_prime[i])
            {
                for (auto j = i * i; j <= limit_sqrt; j += i)
                {
                    is_prime[j] = false;
                }
            }
        }

        // initialize sieving primes for segmented sieve
        for (; s * s <= high; s += 2)
        {
            if (is_prime[s])
            {
                primes.push_back(s);
                multiples.push_back(s * s - low);
            }
        }

        // sieve the current segment
        for (std::size_t i = 0; i < primes.size(); i++)
        {
            auto j = multiples[i];
            for (const auto k = primes[i] * 2; j < segment_size; j += k)
            {
                sieve[j] = false;
            }
            multiples[i] = j - segment_size;
        }

        for (; n <= high; n += 2)
        {
            if (sieve[n - low]) // n is a prime
            {
                if(!act(all_index, n))
                ++all_index;
                //all_primes.push_back(n);
            }
        }
    }
}

template<typename TNum>
std::vector<TNum> get_segmented_sieve(const TNum limit)
{
    std::vector<TNum> primes;
    segmented_sieve<size_t, TNum>(limit, [&primes](size_t, TNum prime)
    {
        primes.push_back(prime);
        return true;
    });
    return primes;
}