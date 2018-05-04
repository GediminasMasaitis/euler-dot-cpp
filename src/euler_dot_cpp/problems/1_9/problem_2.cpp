#include "stdafx.hpp"
#include "problem_2.hpp"
#include "../../common/fibonacci.hpp"

using namespace std;

int64_t impl_2_1::solve()
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

int64_t impl_2_2::solve()
{
    int64_t sum = 0;
    fibonacci_numbers<uint64_t, uint64_t>([&sum](uint64_t, uint64_t fib)
    {
        if(fib > 4000000)
        {
            return false;
        }
        if(fib % 2 == 0)
        {
            sum += fib;
        }
        return true;
    });
    return sum;
}
