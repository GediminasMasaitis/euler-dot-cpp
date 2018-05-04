#pragma once 
#include "../problem_base.hpp"

class impl_2_1 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_2_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_2 : public problem
{
public:
	problem_2()
	{
		id = 2;
		name = "Even Fibonacci numbers";
		answer = 4613732;
        difficulty = 5;
        solved = true;

        add_impl<impl_2_1>();
        add_impl<impl_2_2>();
	}
};
