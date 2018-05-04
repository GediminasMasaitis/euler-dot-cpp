#include "stdafx.hpp"
#include "problem_29.hpp"

using namespace std;
using namespace boost;

int64_t impl_29_1::solve()
{
    return 0; // Really inefficient and stupid bruteforce, disabling
    std::vector<multiprecision::cpp_int> nums;
    for(auto i = 2; i <= 100; i++)
    {
        for (auto j = i; j <= 100; j++)
        {
            const auto arg1 = multiprecision::cpp_int(i);
            const auto num1 = multiprecision::pow(arg1, j);
            if(find(nums.begin(), nums.end(), num1) == nums.end())
            {
                nums.push_back(num1);
            }

            const auto arg2 = multiprecision::cpp_int(j);
            const auto num2 = multiprecision::pow(arg2, i);
            if (find(nums.begin(), nums.end(), num2) == nums.end())
            {
                nums.push_back(num2);
            }

            //cout << arg1 << " " << num1 << " " << num2 << endl;
        }
    }
    return nums.size();
}

int64_t impl_29_2::solve()
{
    // Still bruteforce but less stupid
    std::vector<multiprecision::cpp_int> nums;
    for (auto i = 2; i <= 100; i++)
    {
        multiprecision::cpp_int num = i;
        for (auto j = 2; j <= 100; j++)
        {
            num *= i;
            if (find(nums.begin(), nums.end(), num) == nums.end())
            {
                nums.push_back(num);
            }
        }
    }
    return nums.size();
}