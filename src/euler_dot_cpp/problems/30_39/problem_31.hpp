#pragma once 
#include "../problem_base.hpp"

class impl_31_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_31_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_31_3 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_31 : public problem
{
public:
	problem_31()
	{
		id = 31;
		name = "Coin sums";
		answer = 73682;
        difficulty = 5;
        solved = true;

        add_impl<impl_31_1>();
        add_impl<impl_31_2>();
        add_impl<impl_31_3>();
	}
};
