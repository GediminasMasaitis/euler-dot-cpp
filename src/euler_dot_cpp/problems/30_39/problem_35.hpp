#pragma once 
#include "../problem_base.hpp"

class impl_35_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};


class problem_35 : public problem
{
public:
	problem_35()
	{
		id = 35;
		name = "Circular primes";
		answer = 55;
        difficulty = 5;
        solved = true;

        add_impl<impl_35_1>();
	}
};
