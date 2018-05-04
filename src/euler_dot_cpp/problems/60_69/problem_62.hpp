#pragma once 
#include "../problem_base.hpp"

class impl_62_1 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_62 : public problem
{
public:
    problem_62()
    {
        id = 62;
        name = "Cubic permutations";
        answer = 127035954683;
        difficulty = 15;
        solved = true;

        add_impl<impl_62_1>();
    }
};
