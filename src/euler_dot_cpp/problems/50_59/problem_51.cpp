#include "stdafx.hpp"
#include "problem_51.hpp"

using namespace std;

int64_t impl_51_1::solve()
{
    for(auto total_dig_cnt = 2; total_dig_cnt <= 5; ++total_dig_cnt)
    {
        const auto repl_dig_cnt = total_dig_cnt - 1;
        const auto mask_lim = 1 << repl_dig_cnt;
        for(auto mask = 1; mask < mask_lim; ++mask)
        {
            auto base_mul = 0;
            auto round_mul = 10;
            for(auto mask2 = mask; mask2 != 0; mask2 >>= 1)
            {
                if(mask2 & 1)
                {
                    base_mul += round_mul;
                }
                round_mul *= 10;
            }
        }
    }
    return 0LL;
}