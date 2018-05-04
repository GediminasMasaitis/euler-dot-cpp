#include "stdafx.hpp"
#include "problem_15.hpp"

using namespace std;

static uint64_t get_ways(uint64_t x, uint64_t y, vector<vector<uint64_t>>& cache)
{
    if(x > y)
    {
        const auto temp = x;
        x = y;
        y = temp;
    }
    if (cache[x][y] > 0)
    {
        return cache[x][y];
    }
    uint64_t ways;
    if(x == 0 || y == 0)
    {
        ways = 1;
    }
    else
    {
        ways = get_ways(x - 1, y, cache) + get_ways(x, y - 1, cache);
    }
    cache[x][y] = ways;
    return ways;
}

int64_t impl_15_1::solve()
{
    const auto x = 20;
    const auto y = 20;
    vector<vector<uint64_t>> cache;
    cache.resize(x+1);
    for (auto i = 0; i < y+1; i++)
    {
        cache[i].resize(y+1);
    }
	const auto result = get_ways(x, y, cache);
    return result;
}

int64_t impl_15_2::solve()
{
    const auto x = 20;
    const auto y = 20;
    vector<vector<uint64_t>> mtrx;
    mtrx.resize(x+1);
    for (auto i = 0; i <= y; i++)
    {
        mtrx[i].resize(y+1);
        mtrx[i][0] = 1;
        mtrx[0][i] = 1;
    }
    for (auto i = 1; i <= x; i++)
    {
        for (auto j = 1; j <= y; j++)
        {
            mtrx[i][j] = mtrx[i-1][j] + mtrx[i][j-1];
        }
    }
    return mtrx[x][y];
}
