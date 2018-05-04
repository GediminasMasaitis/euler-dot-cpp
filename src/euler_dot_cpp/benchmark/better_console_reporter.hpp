#pragma once
class MyReporter : public benchmark::ConsoleReporter
{
    benchmark::TimeUnit get_time_unit(const Run& report) const;
    void PrintRunData(const Run& report) override;
};
