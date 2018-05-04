#pragma once 
#include "../problem_base.hpp"

class impl_17_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class problem_17 : public problem
{
public:
	problem_17()
	{
		id = 17;
		name = "Number letter counts";
		answer = 21124;
        difficulty = 5;
        solved = true;

		add_impl<impl_17_1>();
	}
};
