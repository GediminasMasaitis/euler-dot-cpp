#include "stdafx.hpp"
#include "problem_14.hpp"

using namespace std;

int64_t impl_14_1::solve()
{
    auto max_cnt = 0;
    auto max_num = 0;
    constexpr uint64_t limit = 1000000;
	for (uint64_t i = 1; i < limit; ++i)
	{
        auto num = i;
        auto cnt = 1;
	    while (num != 1)
	    {
	        if(num % 2 == 0)
	        {
                num /= 2;
	        }
            else
            {
                num = num * 3 + 1;
            }
            cnt++;
	    }
        if(cnt > max_cnt)
        {
            max_cnt = cnt;
            max_num = i;
        }
	}
    return max_num;
}

int64_t impl_14_2::solve()
{
    auto max_cnt = 0;
    auto max_num = 0;
    constexpr uint64_t limit = 1000000;
    vector<int32_t> cache;
    cache.resize(limit, 0);
    for (uint64_t i = 1; i < limit; ++i)
    {
        auto num = i;
        auto cnt = 1;
        while (num != 1)
        {
            if(num < i)
            {
                cnt += cache[num]-1;
                break;
            }
            if (num % 2 == 0)
            {
                num /= 2;
            }
            else
            {
                num = num * 3 + 1;
            }
            cnt++;
        }
        cache[i] = cnt;
        if (cnt > max_cnt)
        {
            max_cnt = cnt;
            max_num = i;
        }
    }
    return max_num;
}
