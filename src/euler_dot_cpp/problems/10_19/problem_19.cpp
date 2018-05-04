#include "stdafx.hpp"
#include "problem_19.hpp"

using namespace std;
using namespace date;

int64_t impl_19_1::solve()
{
    sys_days d = 1901_y/jan/01;
    const sys_days limit = 2001_y/jan/01;
    uint64_t cnt = 0;
    for(; d < limit;  d += days(1))
    {
        const auto ymd = year_month_day(d);
        if(ymd.day() == 1_d && weekday(d) == sun)
        {
            cnt++;
        }
    }
	return cnt;
}

int64_t impl_19_2::solve()
{
    auto ymd = 1901_y/jan/01;
    const auto limit = 2001_y/jan/01;
    uint64_t cnt = 0;
    for (; ymd < limit; ymd += months(1))
    {
        if (weekday(ymd) == sun)
        {
            cnt++;
        }
    }
    return cnt;
}
