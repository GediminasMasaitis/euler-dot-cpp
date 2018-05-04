#include "stdafx.hpp"
#include "problem_25.hpp"
#include "../../common/fibonacci.hpp"

using namespace std;
using namespace boost;
using namespace multiprecision;

int64_t impl_25_1::solve()
{
    int64_t idx = 0;
    fibonacci_numbers<int64_t, cpp_int>([&idx](int64_t i, cpp_int fib)
    {
        auto str = fib.str();
        if (str.size() >= 1000)
        {
            idx = i;
            return false;
        }
        return true;
    });
    return idx+1;
}