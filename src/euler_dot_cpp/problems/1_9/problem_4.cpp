#include "stdafx.hpp"
#include "problem_4.hpp"
#include "../../common/digits.hpp"

using namespace std;

template<typename T>
bool is_palindrome2(const T num)
{
    const auto str = to_string(num);
    const auto len = str.length();
    const auto halflen = len / 2;
    for(auto i = 0; i < halflen; i++)
    {
        if(str[i] != str[len-i-1])
        {
            return false;
        }
    }
    return true;
}

bool is_palindrome3(const int num)
{
    const auto str = to_string(num);
    auto reverse = str;
    std::reverse_copy(str.begin(), str.end(), reverse.begin());
    return str == reverse;
}

int64_t impl_4_1::solve()
{
    int64_t max = 0;
    for (auto i = 100; i < 1000; i++)
    {
        for (auto j = 100; j < 1000; j++)
        {
            const auto product = i * j;
            const auto pal = is_palindrome2(product);
            if (pal && product > max)
            {
                max = product;
            }
        }
    }
    return max;
}

int64_t impl_4_2::solve()
{
    int64_t max = 0;
    for(auto i = 100; i < 1000; ++i)
    {
        for (auto j = i; j < 1000; ++j)
        {
            const auto product = i * j;
            if(product > max && is_palindrome3(product))
            {
                max = product;
            }
        }
    }
	return max;
}

int64_t impl_4_3::solve()
{
    int64_t max = 0;
    for (auto i = 999; i >= 100; --i)
    {
        for (auto j = i; j >= 100; --j)
        {
            const auto product = i * j;
            if (product > max && is_palindrome3(product))
            {
                max = product;
            }
        }
    }
    return max;
}

int64_t impl_4_4::solve()
{
    int64_t max = 0;
    for (auto i = 999; i >= 100; --i)
    {
        for (auto j = i; j >= 100; --j)
        {
            const auto product = i * j;
            if (product > max && is_palindrome(product))
            {
                max = product;
            }
        }
    }
    return max;
}
