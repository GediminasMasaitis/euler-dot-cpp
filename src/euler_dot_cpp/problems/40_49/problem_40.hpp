#pragma once 
#include "../problem_base.hpp"

class impl_40_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};



class problem_40 : public problem
{
public:
	problem_40()
	{
		id = 40;
		name = "Champernowne's constant";
		answer = 210;
        difficulty = 5;
        solved = true;

        add_impl<impl_40_1>();
	}
};
