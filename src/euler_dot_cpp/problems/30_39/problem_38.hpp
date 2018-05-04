#pragma once 
#include "../problem_base.hpp"

class impl_38_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_38_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};



class problem_38 : public problem
{
public:
	problem_38()
	{
		id = 38;
		name = "Pandigital multiples";
		answer = 932718654;
        difficulty = 5;
        solved = true;

        add_impl<impl_38_1>();
        add_impl<impl_38_2>();
	}
};
