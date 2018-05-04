#include "stdafx.h"
#include "problem_$p.h"

using namespace std;

int64_t impl_$p_1::solve()
{
	auto prev = 1;
	auto num = 1;
	int64_t sum = 0;
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