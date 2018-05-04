#pragma once 
#include "../problem_base.hpp"

class impl_14_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_14_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_14 : public problem
{
public:
	problem_14()
	{
		id = 14;
		name = "Longest Collatz sequence";
		answer = 837799;
        difficulty = 5;
        solved = true;

        add_impl<impl_14_1>();
        add_impl<impl_14_2>();
	}
};
