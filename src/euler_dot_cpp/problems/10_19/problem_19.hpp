#pragma once 
#include "../problem_base.hpp"

class impl_19_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_19_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_19 : public problem
{
public:
	problem_19()
	{
		id = 19;
		name = "Counting Sundays";
		answer = 171;
        difficulty = 5;
        solved = true;

        add_impl<impl_19_1>();
        add_impl<impl_19_2>();
	}
};
