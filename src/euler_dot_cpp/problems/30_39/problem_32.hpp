#pragma once 
#include "../problem_base.hpp"

class impl_32_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};


class problem_32 : public problem
{
public:
	problem_32()
	{
		id = 32;
		name = "Pandigital products";
		answer = 45228;
        difficulty = 5;
        solved = true;

        add_impl<impl_32_1>();
	}
};
