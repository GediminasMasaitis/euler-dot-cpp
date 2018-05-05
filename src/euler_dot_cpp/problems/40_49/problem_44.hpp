#pragma once 
#include "../problem_base.hpp"

class impl_44_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_44_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};


class problem_44 : public problem
{
public:
	problem_44()
	{
		id = 44;
		name = "Pentagon numbers";
		answer = 5482660;
        difficulty = 5;
        solved = true;

        add_impl<impl_44_1>();
        add_impl<impl_44_2>();
	}
};
