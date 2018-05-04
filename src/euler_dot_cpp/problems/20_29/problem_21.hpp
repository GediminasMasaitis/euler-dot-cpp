#pragma once 
#include "../problem_base.hpp"

class impl_21_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_21_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_21_3 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_21 : public problem
{
public:
	problem_21()
	{
		id = 21;
		name = "Amicable numbers";
		answer = 31626;
        difficulty = 5;
        solved = true;

        add_impl<impl_21_1>();
        add_impl<impl_21_2>();
        add_impl<impl_21_3>();
	}
};
