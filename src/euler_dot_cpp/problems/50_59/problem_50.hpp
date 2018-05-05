#pragma once 
#include "../problem_base.hpp"

class impl_50_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_50_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};


class problem_50 : public problem
{
public:
	problem_50()
	{
		id = 50;
		name = "Consecutive prime sum";
		answer = 997651;
        difficulty = 5;
        solved = false;

        add_impl<impl_50_1>();
        add_impl<impl_50_2>();
	}
};
