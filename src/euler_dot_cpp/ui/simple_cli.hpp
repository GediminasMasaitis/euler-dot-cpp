#pragma once
#include "../problems/all_problems.hpp"

#include "ui_base.hpp"

class simple_cli : public ui_base
{
public:
    explicit simple_cli(benchmarker& bm, problems_map& problems);
    void run();
};

