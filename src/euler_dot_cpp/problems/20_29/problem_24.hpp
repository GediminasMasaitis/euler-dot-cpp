#pragma once 
#include "../problem_base.hpp"

class impl_24_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class problem_24 : public problem
{
public:
	problem_24()
	{
		id = 24;
		name = "Lexicographic permutations";
		answer = 2783915460;
        difficulty = 5;
        solved = true;

		add_impl<impl_24_1>();
	}
};
