#pragma once 
#include "../problem_base.hpp"

class impl_42_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};


class problem_42 : public problem
{
public:
    std::vector<std::string> words;

	problem_42()
	{
		id = 42;
		name = "Coded triangle numbers";
		answer = 162;
        difficulty = 5;
        solved = true;

        add_impl<impl_42_1>();
	}

    void init() override;
};
