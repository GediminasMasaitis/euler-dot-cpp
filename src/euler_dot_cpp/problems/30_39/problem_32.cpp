#include "stdafx.hpp"
#include "problem_32.hpp"

#include "../../common/digits.hpp"

using namespace std;

static bool is_pandigital1(string str)
{
    const auto full_pandigital = "123456789"s;
    return std::is_permutation(full_pandigital.begin(), full_pandigital.end(), str.begin(), str.end());
}

int64_t impl_32_1::solve()
{
    constexpr int64_t max = 9876;
    
    google::dense_hash_set<int64_t> pandigitals;
    pandigitals.set_empty_key(-1);
    pandigitals.set_deleted_key(-2);

    for(int64_t i = 1; i <= max; ++i)
    {
        if(!is_pandigital(i, false))
        {
            continue;
        }
        for (int64_t j = i+1; j <= max; ++j)
        {
            if (!is_pandigital(j, false))
            {
                continue;
            }
            const int64_t prod = i * j;
            if (!is_pandigital(prod, false))
            {
                continue;
            }
            const auto ij_pand = concat_num(i, j);
            const auto pand = concat_num(ij_pand, prod);
            if(is_pandigital(pand, true))
            {
                pandigitals.insert(prod);
            }
        }
    }

    int64_t result = 0;
    for(auto pand : pandigitals)
    {
        result += pand;
    }

    return result;
}