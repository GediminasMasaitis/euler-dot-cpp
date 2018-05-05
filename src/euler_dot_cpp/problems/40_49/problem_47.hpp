#pragma once 
#include "../problem_base.hpp"

class impl_47_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_47_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};


class problem_47 : public problem
{
public:
	problem_47()
	{
		id = 47;
		name = "Distinct primes factors";
		answer = 134043;
        difficulty = 5;
        solved = true;

        add_impl<impl_47_1>();
        add_impl<impl_47_2>();
	}
};
