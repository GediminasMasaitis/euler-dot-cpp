#include "stdafx.hpp"
#include "problem_20.hpp"

using namespace std;

int64_t impl_20_1::solve()
{
    boost::multiprecision::cpp_int fact = 1;
    for (auto i = 2; i <= 100; i++)
    {
        fact *= i;
    }
    auto str = fact.str();
    auto sum = 0;
    for (auto ch : str)
    {
        sum += ch - 0x30;
    }
	return sum;
}