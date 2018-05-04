#pragma once
class problem;

class benchmarker
{
public:
    void run_benchmarks(problem& problem, benchmark::BenchmarkReporter& reporter) const;
};

