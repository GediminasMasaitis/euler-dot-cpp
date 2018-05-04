#pragma once
#include "../problem_base.hpp"

class impl_3_1 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_3_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_3 : public problem
{
public:
	problem_3()
	{
		id = 3;
		name = "Largest prime factor";
		answer = 6857;
        difficulty = 5;
        solved = true;

        add_impl<impl_3_1>();
        add_impl<impl_3_2>();
	}
};

