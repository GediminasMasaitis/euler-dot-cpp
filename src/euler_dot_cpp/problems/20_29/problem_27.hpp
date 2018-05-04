#pragma once 
#include "../problem_base.hpp"

class impl_27_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_27_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};


class problem_27 : public problem
{
public:
	problem_27()
	{
		id = 27;
		name = "Quadratic primes";
		answer = -59231;
        difficulty = 5;
        solved = true;

        add_impl<impl_27_1>();
        add_impl<impl_27_2>();
	}
};
