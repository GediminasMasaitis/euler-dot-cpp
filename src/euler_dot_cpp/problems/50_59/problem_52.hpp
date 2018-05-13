#pragma once 
#include "../problem_base.hpp"

class impl_52_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_52_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};


class problem_52 : public problem
{
public:
	problem_52()
	{
		id = 52;
		name = "Permuted multiples";
		answer = 142857;
        difficulty = 5;
        solved = true;

        add_impl<impl_52_1>();
        add_impl<impl_52_2>();
	}
};
