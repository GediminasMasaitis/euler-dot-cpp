#pragma once

template<typename TNum, typename TResult = TNum>
void prime_factors(TNum num, const bool unique, std::function<void(TResult)> act)
{
    if (num % 2 == 0)
    {
        act(static_cast<TResult>(2));
        num /= 2;
    }
    while (num % 2 == 0)
    {
        if (!unique)
        {
            act(static_cast<TResult>(2));
        }
        num /= 2;
    }

    if (num % 3 == 0)
    {
        act(static_cast<TResult>(3));
        num /= 3;
    }
    while (num % 3 == 0)
    {
        if (!unique)
        {
            act(static_cast<TResult>(3));
        }
        num /= 3;
    }

    TResult inc = 2;
    const auto n_sqrt = static_cast<TResult>(sqrt(num));
    for (TResult i = 5; i <= n_sqrt; i += inc, inc ^= 6)
    {
        if (num%i == 0)
        {
            act(i);
            num /= i;
        }
        while (num%i == 0)
        {
            if (!unique)
            {
                act(i);
            }
            num /= i;
        }
    }

    if (num > 2)
    {
        act(static_cast<TResult>(num));
    }
}

template<typename TNum, typename TResult = TNum>
std::vector<TResult> get_prime_factors(TNum num)
{
    std::vector<TResult> factors;
    prime_factors<TNum, TResult>(num, false, [&factors](TResult divisor)
    {
        factors.push_back(divisor);
    });
    return factors;
}

template<typename TNum, typename TResult = TNum>
void proper_divisors(TNum num, std::function<void(TResult)> act)
{
    act(static_cast<TResult>(1));
    const auto lim = static_cast<TResult>(sqrt(num));
    for (TResult j = 2; j <= lim; ++j)
    {
        if (num % j == 0)
        {
            act(j);
            auto div = num / j;
            if (div != j)
            {
                act(div);
            }
        }
    }
}

template<typename TNum, typename TResult = TNum>
std::vector<TResult> get_proper_divisors(TNum num)
{
    std::vector<TResult> divisors;
    proper_divisors<TNum, TResult>(num, [&divisors](TResult divisor)
    {
        divisors.push_back(divisor);
    });
    return divisors;
}