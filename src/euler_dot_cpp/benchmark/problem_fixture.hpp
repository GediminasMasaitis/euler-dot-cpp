#pragma once
#include "../problems/problem_base.hpp"

class problem_fixture : public benchmark::Fixture
{
public:
    problem_impl_base& impl;
    problem& prblm;

    explicit problem_fixture(problem_impl_base& impl);

    void BenchmarkCase(benchmark::State& st) override;
};

