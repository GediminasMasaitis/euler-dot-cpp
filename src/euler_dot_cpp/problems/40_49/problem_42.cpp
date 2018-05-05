#include "stdafx.hpp"
#include "problem_42.hpp"

#include "../../common/io.hpp"

using namespace std;

int64_t impl_42_1::solve()
{
    auto& pr = static_cast<problem_42&>(*prblm);
    constexpr int64_t limit = 26 * 50; // Equivalent to ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
    array<uint8_t, limit> is_triangle{};

    auto triangle = 1;
    for(auto i = 2; triangle < limit; i++)
    {
        is_triangle[triangle] = true;
        triangle += i;
    }

    const auto& words = pr.words;
    int64_t count = 0;
    for (auto i = 0; i < words.size(); i++)
    {
        auto& word = words[i];
        auto score = 0;
        for (auto ch : word)
        {
            score += ch - 0x40;
        }
        if(is_triangle[score])
        {
            count++;
        }
    }

    return count;
}

void problem_42::init()
{
    words = read_string_list("p042_words.txt");
}
