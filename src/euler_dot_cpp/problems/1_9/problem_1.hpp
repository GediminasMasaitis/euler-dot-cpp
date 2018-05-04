#pragma once

#include "../problem_base.hpp"

class impl_1_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_1_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_1_3 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_1_4 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_1 : public problem
{
public:
	problem_1()
	{
		id = 1;
		name = "Multiples of 3 and 5";
		answer = 233168;
        difficulty = 5;
        solved = true;

		add_impl<impl_1_1>();
		add_impl<impl_1_2>();
		add_impl<impl_1_3>();
		add_impl<impl_1_4>();
	}
};