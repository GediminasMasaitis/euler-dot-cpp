#pragma once

template<typename TFrom, typename TTo>
constexpr bool can_cast_exactly(TFrom num)
{
    auto remainder = abs(num - static_cast<TTo>(num));
    return remainder < 0.000000001;
}


template<typename TValue>
constexpr TValue triangle_num(TValue index)
{
    return (index * (index + 1)) / 2;
}

template<typename TValue>
constexpr bool is_triangle_num(TValue num)
{
    const auto inverse_num = (sqrt(static_cast<double>(8 * num + 1)) - 1) / 2;
    return can_cast_exactly<double, TValue>(inverse_num);
}


template<typename TValue>
constexpr TValue square_num(TValue index)
{
    return index * index;
}

template<typename TValue>
constexpr bool is_square_num(TValue num)
{
    const auto inverse_num = sqrt(static_cast<double>(num)) / 2;
    return can_cast_exactly<double, TValue>(inverse_num);
}


template<typename TValue>
constexpr TValue pentagonal_num(TValue index)
{
    return (index * (3*index - 1)) / 2;
}

template<typename TValue>
constexpr bool is_pentagonal_num(TValue num)
{
    const auto inverse_num = (sqrt(static_cast<double>(24 * num + 1)) + 1) / 6;
    return can_cast_exactly<double, TValue>(inverse_num);
}


template<typename TValue>
constexpr TValue hexagonal_num(TValue index)
{
    return index * (2 * index - 1);
}

template<typename TValue>
constexpr bool is_hexagonal_num(TValue num)
{
    const auto inverse_num = (sqrt(static_cast<double>(8 * num + 1)) + 1) / 4;
    return can_cast_exactly<double, TValue>(inverse_num);
}