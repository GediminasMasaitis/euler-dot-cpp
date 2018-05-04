#pragma once
#include "../problems/all_problems.hpp"
#include "../benchmark/benchmarker.hpp"

class ui_base
{
public:
    benchmarker & bm;
    problems_map& problems;

    explicit ui_base(benchmarker& bm, problems_map& problems);
};

