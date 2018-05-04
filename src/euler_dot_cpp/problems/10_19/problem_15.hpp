#pragma once 
#include "../problem_base.hpp"

class impl_15_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_15_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_15 : public problem
{
public:
	problem_15()
	{
		id = 15;
		name = "Lattice paths";
		answer = 137846528820;
        difficulty = 5;
        solved = true;

        add_impl<impl_15_1>();
        add_impl<impl_15_2>();
	}
};
