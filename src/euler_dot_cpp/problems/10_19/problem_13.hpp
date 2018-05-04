#pragma once 
#include "../problem_base.hpp"

class impl_13_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};

class impl_13_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_13_3 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_13_4 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_13 : public problem
{
public:
    std::vector<std::string> data;

    problem_13()
	{
		id = 13;
		name = "Large sum";
		answer = 5537376230;
        difficulty = 5;
        solved = true;

        add_impl<impl_13_1>();
        add_impl<impl_13_2>();
        add_impl<impl_13_3>();
        add_impl<impl_13_4>();
	}

    void init() override;
};
