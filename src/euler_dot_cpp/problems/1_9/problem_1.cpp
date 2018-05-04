#include "stdafx.hpp"
#include "problem_1.hpp"

#include "../../common/basic_math.hpp"

using namespace std;

int64_t impl_1_1::solve()
{
    int64_t sum = 0;
	for (auto i = 0; i < 1000; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}
	return sum;
}

int64_t impl_1_2::solve()
{
    int64_t sum = 0;
	for (auto i = 0; i < 1000; i += 3)
	{
		sum += i;
	}
	for (auto i = 0; i < 1000; i += 5)
	{
		if (i % 3 != 0)
		{
			sum += i;
		}
	}
	return sum;
}

int64_t impl_1_3::solve()
{
    int64_t sum = 0;
	for (auto i = 0; i < 1000; i += 3)
	{
		sum += i;
	}
	for (auto i = 0; i < 1000; i += 5)
	{
		sum += i;
	}
	constexpr auto lcm = lowest_common_multiple(3, 5);
	for (auto i = 0; i < 1000; i += lcm)
	{
		sum -= i;
	}
	return sum;
}

int64_t impl_1_4::solve()
{
	constexpr auto from = 1;
	constexpr auto to = 999;
	auto sum = 0;
	sum += sum_divisible_by(from, to, 3);
	sum += sum_divisible_by(from, to, 5);
	constexpr auto lcm = lowest_common_multiple(3, 5);
	sum -= sum_divisible_by(from, to, lcm);
	return sum;
}

