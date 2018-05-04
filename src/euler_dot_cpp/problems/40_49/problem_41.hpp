#pragma once 
#include "../problem_base.hpp"

class impl_41_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};


class problem_41 : public problem
{
public:
	problem_41()
	{
		id = 41;
		name = "Pandigital prime";
		answer = 0;
        difficulty = 5;
        solved = false;

        add_impl<impl_41_1>();
	}
};
