#pragma once 
#include "../problem_base.hpp"

class impl_16_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_16_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_16 : public problem
{
public:
	problem_16()
	{
		id = 16;
		name = "Power digit sum";
		answer = 1366;
        difficulty = 5;
        solved = true;

        add_impl<impl_16_1>();
        add_impl<impl_16_2>();
	}
};
