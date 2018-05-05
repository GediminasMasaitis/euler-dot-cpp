#include "stdafx.hpp"
#include "problem_43.hpp"

using namespace std;

int64_t impl_43_1::solve()
{
    int64_t sum = 0;
    const std::array<int64_t, 7> divisors{ 2,3,5,7,11,13,17 };
    auto str = "0123456789"s;
    while(str != "9876543210")
    {
        const auto num = stoll(str);
        int64_t trimmer = 1000000;
        auto success = true;
        for(auto i = 0; i < 7; i++)
        {
            int64_t part = (num / trimmer) % 1000;
            if(part % divisors[i] != 0)
            {
                success = false;
                break;
            }
            trimmer /= 10;
        }
        if(success)
        {
            sum += num;
        }
        next_permutation(str.begin(), str.end());
    }

    return sum;
}