#include "stdafx.hpp"
#include "better_console_reporter.hpp"

benchmark::TimeUnit MyReporter::get_time_unit(const Run& report) const
{
    auto it_duration = report.real_accumulated_time / static_cast<double>(report.iterations);
    it_duration *= 1000; // ms
    if (it_duration >= 10)
    {
        return benchmark::kMillisecond;
    }
    it_duration *= 1000; // us
    if (it_duration >= 10)
    {
        return benchmark::kMicrosecond;
    }
    return benchmark::kNanosecond;
}

void MyReporter::PrintRunData(const Run& report)
{
    const auto unit = get_time_unit(report);
    auto& r2 = const_cast<Run&>(report);
    r2.time_unit = unit;
    benchmark::ConsoleReporter::PrintRunData(report);
}
