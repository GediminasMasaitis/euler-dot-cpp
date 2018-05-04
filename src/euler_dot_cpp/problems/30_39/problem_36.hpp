#pragma once 
#include "../problem_base.hpp"

class impl_36_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_36_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};


class problem_36 : public problem
{
public:
	problem_36()
	{
		id = 36;
		name = "Double-base palindromes";
		answer = 872187;
        difficulty = 5;
        solved = true;

        add_impl<impl_36_1>();
        add_impl<impl_36_2>();
	}
};
