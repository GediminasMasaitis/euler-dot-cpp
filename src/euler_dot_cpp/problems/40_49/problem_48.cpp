#include "stdafx.hpp"
#include "problem_48.hpp"

using namespace std;

int64_t impl_48_1::solve()
{
    // Bruteforce
    boost::multiprecision::cpp_int sum = 0;
    for(int64_t i = 1; i <= 1000; ++i)
    {
        const boost::multiprecision::cpp_int i2 = i;
        const auto num = boost::multiprecision::pow(i2, i);
        sum += num;
    }
    const auto last_digits = sum % 10000000000;
    const auto last_digits_int = static_cast<int64_t>(last_digits);
    return last_digits_int;
}

int64_t impl_48_2::solve()
{
    // Bruteforce
    int64_t sum = 0;
    constexpr int64_t mod = 10000000000;
    for (int64_t i = 1; i <= 1000; ++i)
    {
        const auto num = boost::multiprecision::powm(i, i, mod);
        sum += num;
    }
    const auto last_digits = sum % mod;
    return last_digits;
}
