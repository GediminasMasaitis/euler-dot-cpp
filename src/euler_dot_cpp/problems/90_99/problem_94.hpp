#pragma once 
#include "../problem_base.hpp"

class impl_94_1 : public problem_impl_base
{
public:
    int64_t solve() override;
};


class problem_94 : public problem
{
public:
    problem_94()
    {
        id = 94;
        name = "Almost equilateral triangles";
        answer = 0;
        difficulty = 5;
        solved = false;

        add_impl<impl_94_1>();
    }
};
