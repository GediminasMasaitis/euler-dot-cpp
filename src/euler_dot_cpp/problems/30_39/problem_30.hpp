#pragma once 
#include "../problem_base.hpp"

class impl_30_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_30_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_30_3 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_30 : public problem
{
public:
	problem_30()
	{
		id = 30;
		name = "Digit fifth powers";
		answer = 443839;
        difficulty = 5;
        solved = true;

        add_impl<impl_30_1>();
        add_impl<impl_30_2>();
        add_impl<impl_30_2>();
        add_impl<impl_30_3>();
	}
};
