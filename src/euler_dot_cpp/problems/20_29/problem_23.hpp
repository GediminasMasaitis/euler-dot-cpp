#pragma once 
#include "../problem_base.hpp"

class impl_23_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class problem_23 : public problem
{
public:
	problem_23()
	{
		id = 23;
		name = "Non-abundant sums";
		answer = 4179871;
        difficulty = 5;
        solved = true;

		add_impl<impl_23_1>();
	}
};
