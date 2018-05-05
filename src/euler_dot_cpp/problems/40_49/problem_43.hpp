#pragma once 
#include "../problem_base.hpp"

class impl_43_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};


class problem_43 : public problem
{
public:
	problem_43()
	{
		id = 43;
		name = "Sub-string divisibility";
		answer = 16695334890;
        difficulty = 5;
        solved = true;

        add_impl<impl_43_1>();
	}
};
