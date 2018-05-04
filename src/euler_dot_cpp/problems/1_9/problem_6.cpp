#include "stdafx.hpp"
#include "problem_6.hpp"

using namespace std;

template<typename T>
constexpr T sum_of_squares(int up_to)
{
	T sum = 0;
	for(auto i = 1; i <= up_to; i++)
	{
		sum += i * i;
	}
	return sum;
}

template<typename T>
constexpr T square_of_sum(int up_to)
{
	T sum = 0;
	for (auto i = 1; i <= up_to; i++)
	{
		sum += i;
	}
	return sum * sum;
}

int64_t impl_6_1::solve()
{
	constexpr auto result =  square_of_sum<int64_t>(100) - sum_of_squares<int64_t>(100);
	return result;
}