#include "stdafx.hpp"
#include "problem_62.hpp"

using namespace std;

int64_t impl_62_1::solve()
{
    constexpr auto nums = 5;
    std::unordered_map<string, vector<uint64_t>> map;
    for(uint64_t i = 0;; i++)
    {
        const auto cube = i * i * i;
        auto cube_str = to_string(cube);
        std::sort(cube_str.begin(), cube_str.end());
        auto& vec = map[cube_str];
        if(vec.size() == nums - 1)
        {
            return vec.front();
        }
        vec.push_back(cube);
    }
}