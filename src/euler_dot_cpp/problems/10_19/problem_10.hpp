#pragma once 
#include "../problem_base.hpp"


class impl_10_1 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_10_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_10 : public problem
{
public:
	problem_10()
	{
		id = 10;
		name = "Summation of primes";
		answer = 142913828922;
        difficulty = 5;
        solved = true;

        add_impl<impl_10_1>();
        add_impl<impl_10_2>();
	}
};
