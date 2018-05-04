#pragma once 
#include "../problem_base.hpp"

class impl_34_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};


class problem_34 : public problem
{
public:
	problem_34()
	{
		id = 34;
		name = "Digit factorials";
		answer = 40730;
        difficulty = 5;
        solved = true;

        add_impl<impl_34_1>();
	}
};
