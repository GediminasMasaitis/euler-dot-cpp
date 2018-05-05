#pragma once 
#include "../problem_base.hpp"

class impl_33_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};


class problem_33 : public problem
{
public:
	problem_33()
	{
		id = 33;
		name = "Digit cancelling fractions";
		answer = 100;
        difficulty = 5;
        solved = true;

        add_impl<impl_33_1>();
	}
};
