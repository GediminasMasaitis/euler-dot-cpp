#pragma once
#include "../problem_base.hpp"

class impl_4_1 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_4_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_4_3 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_4_4 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_4 : public problem
{
public:
	problem_4()
	{
		id = 4;
		name = "Largest palindrome product";
		answer = 906609;
        difficulty = 5;
        solved = true;

        add_impl<impl_4_1>();
        add_impl<impl_4_2>();
        add_impl<impl_4_3>();
        add_impl<impl_4_4>();
	}
};

