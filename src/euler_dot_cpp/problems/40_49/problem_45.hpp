#pragma once 
#include "../problem_base.hpp"

class impl_45_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_45_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_45 : public problem
{
public:
	problem_45()
	{
		id = 45;
		name = "Triangular, pentagonal, and hexagonal";
		answer = 1533776805;
        difficulty = 5;
        solved = true;

        add_impl<impl_45_1>();
        add_impl<impl_45_2>();
	}
};
