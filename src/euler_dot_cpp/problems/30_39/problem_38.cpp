#include "stdafx.hpp"
#include "problem_38.hpp"
#include "../../common/digits.hpp"

using namespace std;

int64_t impl_38_1::solve()
{
    // 1000010000 is already 10 digits, so the number must be 9876 or less
    constexpr int64_t limit = 9876;
    int64_t max = 0;
    for(int64_t i = limit; i >= 1; --i)
    {
        int64_t num = i;
        auto mul = 2;
        while (num < 123456789)
        {
            const auto prod = i * mul++;
            num = concat_num(num, prod);
        }
        while(num <= 987654321)
        {
            if(num > max && is_pandigital(num, 9))
            {
                max = num;
            }
            const auto prod = i * mul++;
            num = concat_num(num, prod);
        }
    }
    return max;
}

int64_t impl_38_2::solve()
{
    // It's given that starting with 9, the result is 918273645 and it works,
    // so the answer must be either 918273645 itself or greater.
    // That means the starting number must definitely start with a 9,
    // or else the resulting palindrome will be less than the given example.

    // The max possible value can be 9999, since if we take 10000,
    // 1000020000 would be 10 digits. And, since it has to be a palindrome,
    // then the max value can be 9876.

    // This gives us 4 possible cases: it's either 1, 2, 3, or 4 digits.

    // Case 1: The number is 9 and the answer is 918273645
    // Case 2: Min possible is 91, max is 98. Regardless which one you take,
    //   the multiples of 9* will be 2, 3, 3, 3 digits. Which means it's either
    //   2+3+3=8 or 2+3+3+3=11 digits, and we need 9. So it doesn't work.
    //   The starting number can't be 2 digits.
    // Case 3: Min possible is 912, max is 987.
    //   Similarly to case 2, the multiples of 9** are of 3, 4, 4 digits.
    //   So it's either 3+4=7 or 3+4+4=11 digits. We need 9.
    //   The starting number can't be 3 digits either.
    // Case 4: The first multiple of 9*** will be 5 digits, which gives us 4+5=9
    //   This works, and also tells us that in case 4, n = 2.

    // So in order to beat the answer 918273645, the 4-digit number has to be
    // between 9183, and 9876, inclusive. We can iterate in descending order,
    // and if we find a palindrome, the first one we find will be guaranteed
    // to be the maximum possible. And if we don't find any palindromes,
    // then case 1 was correct, 9 is the number and 918273645 is the answer.

    constexpr int64_t hi = 9876;
    constexpr int64_t lo = 9183;
    for (int64_t i = hi; i >= lo; --i)
    {
        const int64_t num = concat_num(i, i*2);
        if (is_pandigital(num, 9))
        {
            return num;
        }
    }
    return 918273645;
}
