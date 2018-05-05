#include "stdafx.hpp"
#include "problem_33.hpp"
#include <valarray>
#include "../../common/basic_math.hpp"

using namespace std;

static bool is_cancelling_correct(const int32_t num1, const int32_t den1, const int32_t num2, const int32_t den2)
{
    const auto div1 = num1 / static_cast<float>(den1);
    const auto div2 = num2 / static_cast<float>(den2);
    return abs(div1 - div2) < 0.0000001;
}

int64_t impl_33_1::solve()
{
    int64_t num_prod = 1;
    int64_t den_prod = 1;
    for(auto num = 10; num <= 99; ++num)
    {
        for (auto den = num+1; den <= 99; ++den)
        {
            const auto num_d1 = num / 10;
            const auto num_d2 = num % 10;
            const auto den_d1 = den / 10;
            const auto den_d2 = den % 10;

            if(num == den)
            {
                continue;
            }
            if(num_d2 % 10 == 0 && den_d2 % 10 == 0)
            {
                continue;
            }

            if (num_d1 == den_d1 && den_d2 != 0)
            {
                if (is_cancelling_correct(num, den, num_d2, den_d2))
                {
                    num_prod *= num;
                    den_prod *= den;
                }
            }
            if(num_d2 == den_d1 && den_d2 != 0)
            {
                if(is_cancelling_correct(num, den, num_d1, den_d2))
                {
                    num_prod *= num;
                    den_prod *= den;
                }
            }
            if (num_d1 == den_d2 && den_d1 != 0)
            {
                if (is_cancelling_correct(num, den, num_d2, den_d1))
                {
                    num_prod *= num;
                    den_prod *= den;
                }
            }
            if (num_d2 == den_d2 && den_d1 != 0)
            {
                if (is_cancelling_correct(num, den, num_d1, den_d1))
                {
                    num_prod *= num;
                    den_prod *= den;
                }
            }
        }
    }
    const auto gcd = greatest_common_denominator(num_prod, den_prod);
    const auto result = den_prod / gcd;
	return result;
}