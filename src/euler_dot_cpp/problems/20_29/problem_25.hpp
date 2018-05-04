#pragma once 
#include "../problem_base.hpp"

class impl_25_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class problem_25 : public problem
{
public:
	problem_25()
	{
		id = 25;
		name = "1000-digit Fibonacci number";
		answer = 4782;
        difficulty = 5;
        solved = true;

		add_impl<impl_25_1>();
	}
};
