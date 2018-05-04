#include "stdafx.hpp"
#include "problem_12.hpp"

#include "../../common/factors.hpp"

using namespace std;

int64_t impl_12_1::solve()
{
    uint64_t sum = 0;
    for(uint64_t i = 1;; ++i)
    {
        sum += i;
        auto cnt = 0;
        const auto lim = static_cast<uint64_t>(sqrt(sum));
        for (uint64_t j = 1; j <= lim; ++j)
        {
            if(sum % j == 0)
            {
                cnt += 2;
            }
        }
        if(cnt > 500)
        {
            return sum;
        }
    }
	return 0;
}

int64_t impl_12_2::solve()
{
    uint64_t sum = 0;
    for (uint64_t i = 1;; ++i)
    {
        sum += i;
        auto factors = get_prime_factors(sum);
        auto cnt = 1;
        auto prev_fac = 0;
        auto fac_cnt = 0;
        for (auto j = 0; j < factors.size(); j++)
        {
            if(prev_fac != factors[j])
            {
                cnt *= fac_cnt + 1;
                fac_cnt = 0;
                prev_fac = factors[j];
            }
            fac_cnt++;
        }
        cnt *= fac_cnt + 1;
        if(cnt > 500)
        {
            return sum;
        }
    }
    return 0;
}
