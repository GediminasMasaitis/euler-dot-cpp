#include "stdafx.hpp"
#include "problem_24.hpp"

using namespace std;

int64_t impl_24_1::solve()
{
    auto num_str = "0123456789"s;
    constexpr auto count = 1000000;
    for(auto i = 0; i < count-1; i++)
    {
        next_permutation(num_str.begin(), num_str.end());
    }
    const auto num = stoull(num_str);
	return num;
}