#include "stdafx.hpp"
#include "problem_47.hpp"
#include "../../common/factors.hpp"

using namespace std;

int64_t impl_47_1::solve()
{
    constexpr int64_t require_consec = 4;
    constexpr int64_t require_factors = 4;

    auto consecutive = 0;
    for(int64_t i = 1;; ++i)
    {
        google::dense_hash_set<int64_t> factors;
        factors.set_empty_key(-1);
        factors.set_deleted_key(-2);
        prime_factors<int64_t, int64_t>(i, false, [&factors](int64_t fact)
        {
            factors.insert(fact);
        });
        if(factors.size() == require_factors)
        {
            consecutive++;
        }
        else
        {
            consecutive = 0;
        }
        if(consecutive == require_consec)
        {
            return i - require_consec + 1;
        }
    }
    return -1;
}

int64_t impl_47_2::solve()
{
    constexpr int64_t require_consec = 4;
    constexpr int64_t require_factors = 4;

    auto consecutive = 0;
    for (int64_t i = 1;; ++i)
    {
        int64_t unique_fact_cnt = 0;
        prime_factors<int64_t, int64_t>(i, true, [&unique_fact_cnt](int64_t fact)
        {
            unique_fact_cnt++;
        });
        if (unique_fact_cnt == require_factors)
        {
            consecutive++;
        }
        else
        {
            consecutive = 0;
        }
        if (consecutive == require_consec)
        {
            return i - require_consec + 1;
        }
    }
    return -1;
}