#pragma once 
#include "../problem_base.hpp"

class impl_12_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_12_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_12 : public problem
{
public:
	problem_12()
	{
		id = 12;
		name = "Highly divisible triangular number";
		answer = 76576500;
        difficulty = 5;
        solved = true;

        add_impl<impl_12_1>();
        add_impl<impl_12_2>();
	}
};
