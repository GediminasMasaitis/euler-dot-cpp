#include "stdafx.hpp"
#include "problem_8.hpp"

#include "../../common/io.hpp"

using namespace std;

int64_t impl_8_1::solve()
{
    const auto& prb = static_cast<problem_8&>(*prblm);
    const auto& str = prb.data;
    constexpr auto n = 13;
    uint64_t max_prod = 0;
    for (auto i = 0; i < str.size()-n; i++)
    {
        uint64_t prod = 1;
        for(auto j = 0; j < n; j++)
        {
            prod *= str[i + j] - 0x30;
        }
        if(prod > max_prod)
        {
            max_prod = prod;
        }
    }
    return max_prod;
}

int64_t impl_8_2::solve()
{
    const auto& prb = static_cast<problem_8&>(*prblm);
    const auto& str = prb.data;
    constexpr auto n = 13;
    uint64_t prod = 0;
    uint64_t max_prod = prod;
    for (auto i = 0; i < str.size(); i++)
    {
        if(prod == 0)
        {
            prod = 1;
            for (const auto to = i + n; i < to; i++)
            {
                prod *= str[i] - 0x30;
            }
            i--;
        }
        else
        {
            prod /= str[i - n] - 0x30;
            prod *= str[i] - 0x30;
        }
        if (prod > max_prod)
        {
            max_prod = prod;
        }
    }
    return max_prod;
}

void problem_8::init()
{
    ifstream ifs;
    open_input("p008_number.txt", ifs);

    stringstream ss;
    while (!ifs.eof())
    {
        string line;
        getline_s(ifs, line, '\n');
        ss << line;
    }
    data = ss.str();
}
