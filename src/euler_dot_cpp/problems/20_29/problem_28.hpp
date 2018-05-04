#pragma once 
#include "../problem_base.hpp"

class impl_28_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_28_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};


class problem_28 : public problem
{
public:
	problem_28()
	{
		id = 28;
		name = "Number spiral diagonals";
		answer = 669171001;
        difficulty = 5;
        solved = true;

        add_impl<impl_28_1>();
        add_impl<impl_28_2>();
	}
};
