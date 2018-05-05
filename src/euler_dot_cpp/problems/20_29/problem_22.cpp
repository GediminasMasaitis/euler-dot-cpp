#include "stdafx.hpp"
#include "problem_22.hpp"
#include "../../common/io.hpp"

using namespace std;

int64_t impl_22_1::solve()
{
    auto total = 0;
    auto& pr = static_cast<problem_22&>(*prblm);
    auto names = pr.names;
    std::sort(names.begin(), names.end());
    for(auto i = 0; i < names.size(); i++)
    {
        auto& name = names[i];
        auto score = 0;
        for(auto ch : name)
        {
            score += ch - 0x40;
        }
        score *= i;
        total += score;
    }
	return total;
}

void problem_22::init()
{
    names = read_string_list("p022_names.txt");
}
