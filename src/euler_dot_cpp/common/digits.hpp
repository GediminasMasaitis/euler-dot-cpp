#pragma once
#include "alg_common.hpp"

template<typename TValue>
constexpr size_t get_digit_count(TValue value, const int32_t base = 10)
{
    uint32_t i = 0;
    while (value != 0)
    {
        value /= base;
        i++;
    }
    return i;
}

template<typename T>
constexpr T concat_num(T lhs, T rhs, const int32_t base = 10)
{
    auto mul = get_digit_count(rhs, base);
    for(; mul != 0; --mul)
    {
        lhs *= base;
    }
    return lhs + rhs;
}

template<typename T>
constexpr bool is_palindrome(T num, const int32_t base = 10)
{
    constexpr auto max_size = sizeof(T) * 8;
    std::array<T, max_size> digits;
    size_t len = 0;
    while (num != 0)
    {
        digits[len] = num % base;
        num /= base;
        len++;
    }
    const auto limit = len / 2;
    for (auto i = 0; i < limit; i++)
    {
        if (digits[i] != digits[len - i - 1])
        {
            return false;
        }
    }
    return true;
}

template<typename TValue>
constexpr bool is_pandigital(TValue num, const bool full, const int32_t base = 10)
{
    TValue bitmask = 0;
    auto count = 0;

    while (num != 0)
    {
        const auto prev_mask = bitmask;
        const auto digit = num % base;
        if (digit == 0)
        {
            return false;
        }
        bitmask |= static_cast<TValue>(1 << digit);
        if (prev_mask == bitmask)
        {
            return false;
        }

        count++;
        num /= base;
    }
    return !full || (count == base - 1);
}

template<typename TValue, typename TDigit>
constexpr void unordered_get_digits(TValue num, alg_idx_res_pred<uint32_t, TDigit> pred, const int32_t base = 10)
{
    for (uint32_t i = 0; num != 0; i++)
    {
        const auto digit = static_cast<TDigit>(i, num % base);
        if (!pred(i, digit))
        {
            return;
        }
        num /= base;
    }
}