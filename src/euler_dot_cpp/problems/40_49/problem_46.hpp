#pragma once 
#include "../problem_base.hpp"

class impl_46_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};


class problem_46 : public problem
{
public:
	problem_46()
	{
		id = 46;
		name = "Goldbach's other conjecture";
		answer = 5777;
        difficulty = 5;
        solved = true;

        add_impl<impl_46_1>();
	}
};
