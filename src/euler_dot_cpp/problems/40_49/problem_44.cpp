#include "stdafx.hpp"
#include "problem_44.hpp"

#include "../../common/ngonal_numbers.h"

using namespace std;

int64_t impl_44_1::solve()
{
    // Tried this approach, realized I got the problem wrong, the numbers don't have to be consecutive.
    // And also it's too slow.
    return 0;
    google::dense_hash_set<int64_t> pentagonals{};
    pentagonals.set_deleted_key(-1);
    pentagonals.set_empty_key(-2);
    pentagonals.insert(1);
    pentagonals.insert(5);
    int64_t max_idx = 2;
    int64_t max_pent = 5;
    int64_t prev_pent = 1;
    for (int64_t i = 2;; ++i)
    {
        const auto pent = pentagonal_num(i);
        const auto diff = pent - prev_pent;
        const auto sum = pent + prev_pent;
        while (max_pent <= sum)
        {
            max_pent = pentagonal_num(++max_idx);
            pentagonals.insert(max_pent);
        }
        if (pentagonals.find(diff) != pentagonals.end())
        {
            if (pentagonals.find(sum) != pentagonals.end())
            {
                return diff;
            }
        }
        prev_pent = pent;
    }
    return -1;
}

int64_t impl_44_2::solve()
{
    for(int64_t i = 1;; ++i)
    {
        const auto i_pent = pentagonal_num(i);
        for (int64_t j = 1; j < i ; ++j)
        {
            const auto j_pent = pentagonal_num(j);
            const auto diff = i_pent - j_pent;
            if(!is_pentagonal_num(diff))
            {
                continue;
            }
            const auto sum =  i_pent + j_pent;
            if (!is_pentagonal_num(sum))
            {
                continue;
            }
            return diff;
        }
    }
    return -1;
}