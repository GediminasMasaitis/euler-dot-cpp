#pragma once 
#include "../problem_base.hpp"

class impl_48_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_48_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_48_3 : public problem_impl_base
{
public:
    int64_t solve() override;
};


class problem_48 : public problem
{
public:
	problem_48()
	{
		id = 48;
		name = "Self powers";
		answer = 9110846700;
        difficulty = 5;
        solved = true;

        add_impl<impl_48_1>();
        add_impl<impl_48_2>();
        add_impl<impl_48_3>();
	}
};
