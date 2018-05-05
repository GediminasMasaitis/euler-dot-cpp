#pragma once
template<typename TValue>
constexpr TValue triangle_num(TValue index)
{
    return (index * (index + 1)) / 2;
}

template<typename TValue>
constexpr TValue square_num(TValue index)
{
    return index * index;
}

template<typename TValue>
constexpr TValue pentagonal_num(TValue index)
{
    return (index * (3*index - 1)) / 2;
}

template<typename TValue>
constexpr bool is_pentagonal_num(TValue num)
{
    auto added = 1 + 24 * num;
    auto inverse_num = (sqrt(static_cast<double>(added)) + 1) / 6;
    auto remainder = abs(inverse_num - static_cast<TValue>(inverse_num));
    return remainder < 0.000000001;
}