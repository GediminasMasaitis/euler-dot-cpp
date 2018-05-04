#pragma once 
#include "../problem_base.hpp"

class impl_37_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_37_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_37_3 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_37 : public problem
{
public:
	problem_37()
	{
		id = 37;
		name = "Truncatable primes";
		answer = 748317;
        difficulty = 5;
        solved = true;

        add_impl<impl_37_1>();
        add_impl<impl_37_2>();
        add_impl<impl_37_3>();
	}
};
