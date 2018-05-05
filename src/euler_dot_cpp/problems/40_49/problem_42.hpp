#pragma once 
#include "../problem_base.hpp"

class impl_42_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};


class problem_42 : public problem
{
public:
	problem_42()
	{
		id = 42;
		name = "";
		answer = 0;
        difficulty = 5;
        solved = false;

        add_impl<impl_42_1>();
	}
};
