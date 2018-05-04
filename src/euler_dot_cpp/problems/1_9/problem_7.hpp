#pragma once 
#include "../problem_base.hpp"

class impl_7_1 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_7_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_7_3 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_7 : public problem
{
public:
	problem_7()
	{
		id = 7;
		name = "10001st prime";
		answer = 104743;
        difficulty = 5;
        solved = true;

		add_impl<impl_7_1>();
        add_impl<impl_7_2>();
        add_impl<impl_7_3>();
	}
};
