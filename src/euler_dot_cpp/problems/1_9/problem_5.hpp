#pragma once 
#include "../problem_base.hpp"

class impl_5_1 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_5_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_5_3 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_5 : public problem
{
public:
    problem_5()
    {
        id = 5;
        name = "Smallest multiple";
        answer = 232792560;
        difficulty = 5;
        solved = true;

        add_impl<impl_5_1>();
        add_impl<impl_5_2>();
        add_impl<impl_5_3>();
    }
};
