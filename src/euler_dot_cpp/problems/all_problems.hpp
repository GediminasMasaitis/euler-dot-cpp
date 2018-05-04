#pragma once
#include "problem_base.hpp"


using problems_map = std::map<int32_t, std::unique_ptr<problem>>;

void init_problems(problems_map& problems);