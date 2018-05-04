#include "stdafx.hpp"
#include "benchmarker.hpp"

#include "../problems/problem_base.hpp"
#include "problem_fixture.hpp"

using namespace std;

void benchmarker::run_benchmarks(problem& problem, benchmark::BenchmarkReporter& reporter) const
{
    for (auto i = 0; i < problem.impls.size(); i++)
    {
        auto& impl = problem.impls[i];
        auto bmf = new problem_fixture(*impl);
        bmf->Args({ problem.id, i });
        benchmark::internal::RegisterBenchmarkInternal(bmf);
    }

    benchmark::RunSpecifiedBenchmarks(&reporter);
    benchmark::ClearRegisteredBenchmarks();
}