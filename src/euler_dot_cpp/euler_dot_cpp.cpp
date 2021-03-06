// euler_dot_cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.hpp"
#include "problems/all_problems.hpp"
#include "ui/simple_cli.hpp"
#include "benchmark/benchmarker.hpp"

using namespace std;

int main(int argc, char** argv)
{
    problems_map problems;
    benchmarker bm;
    init_problems(problems);
    simple_cli ui(bm, problems);

    ui.run();

    return 0;
}

