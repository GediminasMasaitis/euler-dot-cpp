#pragma once 
#include "../problem_base.hpp"

class impl_26_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_26_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_26_3 : public problem_impl_base
{
public:
    int64_t solve() override;
};


class problem_26 : public problem
{
public:
	problem_26()
	{
		id = 26;
		name = "Reciprocal cycles";
		answer = 983;
        difficulty = 5;
        solved = true;

        add_impl<impl_26_1>();
        add_impl<impl_26_2>();
        add_impl<impl_26_3>();
	}
};
