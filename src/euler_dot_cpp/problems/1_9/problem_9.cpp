#include "stdafx.hpp"
#include "problem_9.hpp"
#include "../../common/pythagoras.hpp"

using namespace std;

int64_t impl_9_1::solve()
{
    constexpr uint64_t num = 1000;
    for(uint64_t a = 1; a < num; a++)
    {
        const auto asq = a * a;
        for (uint64_t b = a; b < num; b++)
        {
            const auto bsq = b * b;
            const auto csq = asq + bsq;
            const auto c = (uint64_t)sqrt(csq);
            if(c*c != csq)
            {
                continue;
            }
            if(a+b+c == num)
            {
                return a * b*c;
            }
        }
    }
    return 0;
}


int64_t impl_9_2::solve()
{
    constexpr uint64_t num = 1000;

    array<uint64_t, num> squares;
    for(uint64_t i = 0; i < num; i++)
    {
        const auto square = i * i;
        squares[i] = square;
    }

    for (uint64_t a = 1; a < num; a++)
    {
        const auto asq = squares[a];
        for (uint64_t b = a; b < num; b++)
        {
            const auto bsq = squares[b];
            const auto csq = asq + bsq;
            const auto c = (uint64_t)sqrt(csq);
            if (c*c != csq)
            {
                continue;
            }
            if (a + b + c == num)
            {
                return a * b*c;
            }
        }
    }
    return 0;
}

int64_t impl_9_3::solve()
{
    constexpr uint64_t num = 1000;
    
    for(auto i = 2; i < num; i++)
    {
        for (auto j = i+1; j < num; ++j)
        {
            const auto a_base = j * j - i * i;
            const auto b_base = 2 * i*j;
            const auto c_base = j * j + i * i;

            if (c_base > num)
            {
                break;
            }

            for(auto k = 1; k < num; k++)
            {
                const auto a = a_base * k;
                const auto b = b_base * k;
                const auto c = c_base * k;
                const auto sum = a + b + c;
                if(sum > num)
                {
                    break;
                }

                if (sum == num)
                {
                    return a * b * c;
                }
            }
        }
    }
    return 0;
}

int64_t impl_9_4::solve()
{
    constexpr uint64_t num = 1000;

    for (auto k = 1; k < num; k++)
    {
        for (auto i = 2; i < num; i++)
        {
            // TODO: Can we do this?
            /*if(2*i*i*k > num)
            {
                break;
            }*/
            for (auto j = i + 1; j < num; ++j)
            {
                const auto a = (j * j - i * i)*k;
                const auto b = (2 * i*j)*k;
                const auto c = (j * j + i * i)*k;
                const auto sum = a + b + c;

                if (sum > num)
                {
                    break;
                }

                if (sum == num)
                {
                    return a * b * c;
                }
            }
        }
    }
    return 0;
}

int64_t impl_9_5::solve()
{
    int64_t result = 0;
    constexpr int64_t limit = 1000;
    pythagorean_triplets_old<int64_t>(limit, [limit, &result](const auto& trip)
    {
        if(trip.sum == limit)
        {
            result = trip.a() * trip.b() * trip.c();
            return false;
        }
        return true;
    });
    return result;
}

int64_t impl_9_6::solve()
{
    int64_t result = 0;
    constexpr int64_t limit = 1000;
    pythagorean_triplets_unique_old<int64_t>(limit, [limit, &result](const auto& trip)
    {
        if (trip.sum == limit)
        {
            result = trip.a() * trip.b() * trip.c();
            return false;
        }
        return true;
    });
    return result;
}
