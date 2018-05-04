#include "stdafx.hpp"
#include "problem_fixture.hpp"

problem_fixture::problem_fixture(problem_impl_base& impl): impl(impl), prblm(*impl.prblm)
{
    this->SetName("Prb");
    if (prblm.requires_reinit || impl.requires_reinit)
    {
        this->SetName("Prb/Reinit");
    }
    prblm.init();
    impl.init();
}

void problem_fixture::BenchmarkCase(benchmark::State& st)
{
    int64_t result = 0;

    if (!prblm.requires_reinit && !impl.requires_reinit)
    {
        while (st.KeepRunning())
        {
            result = impl.solve();
        }
    }
    else
    {
        while (st.KeepRunning())
        {
            st.PauseTiming();
            if (prblm.requires_reinit)
            {
                prblm.reinit();
            }
            if (impl.requires_reinit)
            {
                impl.reinit();
            }
            st.ResumeTiming();
            result = impl.solve();
        }
    }

    std::stringstream label_sb;
    auto longest_name_length = 25;
    label_sb << std::setw(longest_name_length) << std::left << prblm.name << " --> " << std::setw(19) << std::right <<
        result;
    if (result != prblm.answer)
    {
        label_sb << " (INCORRECT!)";
    }
    st.SetLabel(label_sb.str());
    //st.counters["Result"] = result;
    //st.counters["Correct"] = result == prblm.answer;
}
