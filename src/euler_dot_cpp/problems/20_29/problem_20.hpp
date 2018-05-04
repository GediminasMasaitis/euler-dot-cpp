#pragma once 
#include "../problem_base.hpp"

class impl_20_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class problem_20 : public problem
{
public:
	problem_20()
	{
		id = 20;
		name = "Factorial digit sum";
		answer = 648;
        difficulty = 5;
        solved = true;

		add_impl<impl_20_1>();
	}
};
