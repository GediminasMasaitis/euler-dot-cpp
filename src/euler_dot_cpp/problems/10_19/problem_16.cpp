#include "stdafx.hpp"
#include "problem_16.hpp"

using namespace std;
using namespace boost;

static uint64_t get_answer(multiprecision::uint1024_t& num)
{
    auto str = num.str();
    auto sum = 0;
    for (auto ch : str)
    {
        sum += ch - 0x30;
    }
    return sum;
}

int64_t impl_16_1::solve()
{
    multiprecision::uint1024_t num(1);
    for(auto i = 0; i < 1000; i++)
    {
        num *= 2;
    }
	return get_answer(num);
}

int64_t impl_16_2::solve()
{
    auto num = multiprecision::pow(multiprecision::uint1024_t(2), 1000);
    return get_answer(num);
}
