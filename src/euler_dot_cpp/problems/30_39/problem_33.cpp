#include "stdafx.hpp"
#include "problem_33.hpp"

using namespace std;

int64_t impl_33_1::solve()
{
	auto prev = 1;
	auto num = 1;
	auto sum = 0;
	while(num < 4000000)
	{
		const auto temp = num;
		num += prev;
		prev = temp;
		if (num % 2 == 0)
		{
			sum += num;
		}
	}
	return sum;
}