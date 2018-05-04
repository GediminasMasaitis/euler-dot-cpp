#pragma once 
#include "../problem_base.hpp"

class impl_29_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_29_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_29 : public problem
{
public:
	problem_29()
	{
		id = 29;
		name = "Distinct powers";
		answer = 9183;
        difficulty = 5;
        solved = true;

        add_impl<impl_29_1>();
        add_impl<impl_29_2>();
	}
};
