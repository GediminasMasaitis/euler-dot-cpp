#pragma once
#include "alg_common.hpp"
#include "basic_math.hpp"

template<typename T>
using pythagorean_arr_t = std::array<T, 3>;

template<typename T>
using pythagorean_mtrx_t = std::array<pythagorean_arr_t<T>, 3>;

template<typename T>
struct pythagorean_triplet
{
    pythagorean_arr_t<T> arr;
    T sum;

    T& a() { return arr[0]; }
    T& b() { return arr[1]; }
    T& c() { return arr[2]; }

    const T& a() const { return arr[0]; }
    const T& b() const { return arr[1]; }
    const T& c() const { return arr[2]; }

    void calc_sum()
    {
        sum = a() + b() + c();
    }
};

template<typename TValue>
void pythagorean_triplets_old(const TValue limit, alg_res_ref_pred<pythagorean_triplet<TValue>> pred)
{
    for (TValue k = 1; k < limit; ++k)
    {
        for (TValue i = 1; i < limit; ++i)
        {
            // TODO: Can we do this?
            /*if(2*i*i*k > limit)
            {
                break;
            }*/
            for (TValue j = i + 1; j < limit; j += 2)
            {
                /*auto gcd = greatest_common_denominator(i, j);
                if(gcd != 1)
                {
                    continue;
                }*/
                pythagorean_triplet<TValue> trip;
                trip.a() = (j * j - i * i)*k;
                trip.b() = (2 * i*j)*k;
                trip.c() = (j * j + i * i)*k;
                trip.calc_sum();

                /*if(trip.a > trip.b)
                {
                    continue;
                }*/

                if (trip.sum > limit)
                {
                    break;
                }

                if (!pred(trip))
                {
                    return;
                }
            }
        }
    }
}

template<typename TValue>
void pythagorean_triplets_unique_old(const TValue limit, alg_res_ref_pred<pythagorean_triplet<TValue>> pred)
{
    for (TValue i = 1; i < limit; ++i)
    {
        for (TValue j = i + 1; j < limit; j += 2)
        {
            auto gcd = greatest_common_denominator(i, j);
            if(gcd != 1)
            {
                continue;
            }
            for (TValue k = 1; k < limit; ++k)
            {
                pythagorean_triplet<TValue> trip;
                trip.a() = (j * j - i * i)*k;
                trip.b() = (2 * i*j)*k;
                trip.c() = (j * j + i * i)*k;
                trip.calc_sum();

                if (trip.sum >= limit)
                {
                    break;
                }

                if (!pred(trip))
                {
                    return;
                }
            }
        }
    }
}

template<typename TValue, size_t VSize>
void dot_prod(const std::array<TValue, VSize>& arr, const std::array<std::array<TValue, VSize>, VSize>& mtrx, std::array<TValue, VSize>& result)
{
    //array<int64_t, VSize> result {};
    for (size_t i = 0; i < VSize; i++)
    {
        for (size_t j = 0; j < VSize; j++)
        {
            result[j] += mtrx[i][j] * arr[i];
        }
    }
}

template<typename TValue>
pythagorean_triplet<TValue> next_triplet(const pythagorean_triplet<TValue>& trip, const pythagorean_mtrx_t<TValue>& mtrx)
{
    pythagorean_triplet<TValue> result{};
    dot_prod(trip.arr, mtrx, result.arr);
    result.calc_sum();
    return result;
}

template<typename TValue>
void pythagorean_triplets_primitive(TValue limit, alg_res_ref_pred<pythagorean_triplet<TValue>> pred)
{
    using mtrxs_t = std::array<pythagorean_mtrx_t<TValue>, 3>;

    const mtrxs_t uad
    {
        1,  2,  2,
        -2, -1, -2,
        2,  2,  3,

        1,  2,  2,
        2,  1,  2,
        2,  2,  3,

        -1, -2, -2,
        2,  1,  2,
        2,  2,  3
    };

    pythagorean_triplet<TValue> initial;
    initial.a() = 3;
    initial.b() = 4;
    initial.c() = 5;
    initial.calc_sum();
    if (!pred(initial))
    {
        return;
    }

    //std::queue<pythagorean_triplet<TValue>> pending;
    std::stack<pythagorean_triplet<TValue>> pending;
    pending.push(initial);

    while (!pending.empty())
    {
        //const auto& trip = pending.front();
        const auto trip = pending.top();
        pending.pop();
        for (auto i = 0; i < 3; ++i)
        {
            auto next = next_triplet<TValue>(trip, uad[i]);
            if (next.sum >= limit)
            {
                continue;
            }
            if (!pred(next))
            {
                return;
            }
            pending.push(next);
        }
    }
}

template<typename TValue>
void pythagorean_triplets_all(TValue limit, alg_res_ref_pred<pythagorean_triplet<TValue>> pred)
{
    pythagorean_triplets_primitive<TValue>(limit, [limit, &pred](const pythagorean_triplet<TValue>& trip)
    {
        auto trip2 = trip;
        while (trip2.sum < limit)
        {
            if (!pred(trip2))
            {
                return false;
            }
            trip2.a() += trip.a();
            trip2.b() += trip.b();
            trip2.c() += trip.c();
            trip2.sum += trip.sum;
        }
        return true;
    });
}