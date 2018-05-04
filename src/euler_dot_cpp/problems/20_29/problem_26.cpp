#include "stdafx.hpp"
#include "problem_26.hpp"

using namespace std;

int64_t impl_26_1::solve()
{
    constexpr uint64_t limit = 1000;
    uint64_t max = 0;
    uint64_t max_div = 0;
    vector<int32_t> carries;
    for (uint64_t divisor = 2; divisor < limit; divisor++)
    {
        carries.clear();
        auto num = 1;
        while (true)
        {
            num *= 10;
            const auto res = num / divisor;
            const auto mul = res * divisor;
            const auto carry = static_cast<int32_t>(num - mul);
            if (carry == 0)
            {
                break;
            }
            num -= mul;
            const auto it = std::find(carries.begin(), carries.end(), carry);
            if (it != carries.end())
            {
                const uint64_t len = carries.end() - it;
                if (len > max)
                {
                    max = len;
                    max_div = divisor;
                }
                break;
            }
            carries.push_back(carry);
        }
    }
    return max_div;
}

int64_t impl_26_2::solve()
{
    constexpr uint64_t limit = 1000;
    uint64_t max = 0;
    uint64_t max_div = 0;
    unordered_map<int32_t, uint64_t> carries;
    for (uint64_t divisor = 2; divisor < limit; divisor++)
    {
        carries.clear();
        auto num = 1;
        //while (true)
        for(auto i = 0;; i++)
        {
            num *= 10;
            const auto res = num / divisor;
            const auto mul = res * divisor;
            const auto carry = static_cast<int32_t>(num - mul);
            if (carry == 0)
            {
                break;
            }
            num -= mul;
            //const auto it = std::find(carries.begin(), carries.end(), carry);
            const auto it = carries.find(carry);
            if (it != carries.end())
            {
                const uint64_t len = i - it->second;
                if (len > max)
                {
                    max = len;
                    max_div = divisor;
                }
                break;
            }
            carries.insert(std::make_pair(carry, i));
        }
    }
    return max_div;
}


int64_t impl_26_3::solve()
{
    constexpr uint64_t limit = 1000;
    uint64_t max = 0;
    uint64_t max_div = 0;
    google::dense_hash_map<int32_t, uint64_t> carries;
    carries.set_empty_key(-1);
    carries.set_deleted_key(-2);
    for (uint64_t divisor = 2; divisor < limit; divisor++)
    {
        carries.clear();
        auto num = 1;
        //while (true)
        for (auto i = 0;; i++)
        {
            num *= 10;
            const auto res = num / divisor;
            const auto mul = res * divisor;
            const auto carry = static_cast<int32_t>(num - mul);
            if (carry == 0)
            {
                break;
            }
            num -= mul;
            //const auto it = std::find(carries.begin(), carries.end(), carry);
            const auto it = carries.find(carry);
            if (it != carries.end())
            {
                const uint64_t len = i - it->second;
                if (len > max)
                {
                    max = len;
                    max_div = divisor;
                }
                break;
            }
            carries.insert(std::make_pair(carry, i));
        }
    }
    return max_div;
}
