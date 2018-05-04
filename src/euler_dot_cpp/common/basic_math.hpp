#pragma once
#include "transform_sequence.hpp"

template<typename T>
constexpr T greatest_common_denominator(const T a, const T b)
{
	return b == 0 ? a : greatest_common_denominator(b, a % b);
}

template<typename T>
constexpr T lowest_common_multiple(const T a, const T b)
{
	const auto gcd = greatest_common_denominator(a, b);
	return gcd ? (a / gcd * b) : 0;
}

template<typename T>
constexpr T sum_divisible_by(const T from, const T to, const T divisor)
{
	const auto cycles = to / divisor;
	const auto min = from * divisor;
	const auto max = cycles * divisor;
	const auto sum = ((min + max) * cycles) / 2;
	return sum;
}

template<typename T>
constexpr T sum_up_to(const T from, const T to)
{
	return sum_divisible_by(from, to, 1);
}

template<typename TValue, typename TIndex>
constexpr TValue factorial(TIndex num)
{
    TValue fact = 1;
    for (TIndex i = 2; i <= num; ++i)
    {
        fact *= i;
    }
    return fact;
}

template
<
    typename TValue,
    typename TIndex,
    TIndex VFrom,
    TIndex VTo
>
using factorial_sequence = transform_sequence_templ<TValue, TIndex, VFrom, VTo, &factorial<TValue, TIndex>>;