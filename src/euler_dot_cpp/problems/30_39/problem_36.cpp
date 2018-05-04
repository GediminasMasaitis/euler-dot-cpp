#include "stdafx.hpp"
#include "problem_36.hpp"
#include "../../common/digits.hpp"

using namespace std;

int64_t impl_36_1::solve()
{

	int64_t sum = 0;
	for(auto i = 1; i < 1000000; i += 2)
	{
        if(!is_palindrome(i, 10))
        {
            continue;
        }
        if(!is_palindrome(i, 2))
        {
            continue;
        }
        sum += i;
	}
	return sum;
}

//template<typename T, T(*lzcnt)(T), T(*tzcnt)(T)>
bool is_palindrome_bin(uint64_t num)
{
    const auto start = _lzcnt_u64(num);
    while(num != 0)
    {
        const auto st = _lzcnt_u64(num);
        const auto end = _tzcnt_u64(num);
        if(st - start != end)
        {
            return false;
        }
        num &= ~(1ULL << (63 - st));
        num &= ~(1ULL << end);
    }
    return true;
}

int64_t impl_36_2::solve()
{
    int64_t sum = 0;
    for (auto i = 1; i < 1000000; i += 2)
    {
        if (!is_palindrome_bin(i))
        {
            continue;
        }
        if (!is_palindrome(i, 10))
        {
            continue;
        }
        sum += i;
    }
    return sum;
}
