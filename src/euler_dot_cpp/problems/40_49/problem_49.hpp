#pragma once 
#include "../problem_base.hpp"

class impl_49_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};


class problem_49 : public problem
{
public:
	problem_49()
	{
		id = 49;
		name = "Prime permutations";
		answer = 296962999629;
        difficulty = 5;
        solved = true;

        add_impl<impl_49_1>();
	}
};
