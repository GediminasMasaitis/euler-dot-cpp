#pragma once 
#include "../problem_base.hpp"

class impl_51_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};


class problem_51 : public problem
{
public:
	problem_51()
	{
		id = 51;
		name = "Prime digit replacements";
		answer = 0;
        difficulty = 5;
        solved = false;

        add_impl<impl_51_1>();
	}
};
