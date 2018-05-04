#pragma once 
#include "../problem_base.hpp"

class impl_9_1 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_9_2 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_9_3 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_9_4 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_9_5 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class impl_9_6 : public problem_impl_base
{
public:
    int64_t solve() override;
};

class problem_9 : public problem
{
public:
    problem_9()
    {
        id = 9;
        name = "Special Pythagorean triplet";
        answer = 31875000;
        difficulty = 5;
        solved = true;

        add_impl<impl_9_1>();
        add_impl<impl_9_2>();
        add_impl<impl_9_3>();
        add_impl<impl_9_4>();
        add_impl<impl_9_5>();
        add_impl<impl_9_6>();
    }
};
