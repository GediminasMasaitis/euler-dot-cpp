#pragma once 
#include "../problem_base.hpp"

class impl_8_1 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_8_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_8 : public problem
{
public:
    std::string data;

    void init() override;

    problem_8()
    {
        id = 8;
        name = "Largest product in a series";
        answer = 23514624000;
        difficulty = 5;
        solved = true;

        add_impl<impl_8_1>();
        add_impl<impl_8_2>();
    }
};
