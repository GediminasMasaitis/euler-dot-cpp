#pragma once 
#include "../problem_base.hpp"

class impl_6_1 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_6 : public problem
{
public:
	problem_6()
	{
		id = 6;
		name = "Sum square difference";
		answer = 25164150;
        difficulty = 5;
        solved = true;

		add_impl<impl_6_1>();
	}
};
