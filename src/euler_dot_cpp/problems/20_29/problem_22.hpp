#pragma once 
#include "../problem_base.hpp"

class impl_22_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class problem_22 : public problem
{
public:
    std::vector<std::string> names;
    
	problem_22()
	{
		id = 22;
		name = "Names scores";
		answer = 871198282;
        difficulty = 5;
        solved = true;

		add_impl<impl_22_1>();
	}

    void init() override;
};
