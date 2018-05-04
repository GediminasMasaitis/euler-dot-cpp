#pragma once 
#include "../problem_base.hpp"

class impl_39_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_39_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_39_3 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_39 : public problem
{
public:
	problem_39()
	{
		id = 39;
		name = "Integer right triangles";
		answer = 840;
        difficulty = 5;
        solved = true;

        add_impl<impl_39_1>();
        add_impl<impl_39_2>();
        add_impl<impl_39_3>();
	}
};
