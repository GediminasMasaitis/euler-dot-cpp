#pragma once 
#include "../problem_base.hpp"

class impl_11_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class problem_11 : public problem
{
public:
    using data_t = uint64_t;
    std::vector<std::vector<data_t>> data;

	problem_11()
	{
		id = 11;
		name = "Largest product in a grid";
		answer = 70600674;
        difficulty = 5;
        solved = true;

		add_impl<impl_11_1>();
	}

    void init() override;
};
