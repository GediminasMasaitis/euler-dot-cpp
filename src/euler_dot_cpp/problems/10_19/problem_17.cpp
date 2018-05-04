#include "stdafx.hpp"
#include "problem_17.hpp"

using namespace std;

const static auto ones = array<string, 10>
{
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

const static auto teens = array<string, 10>
{
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen"
};

const static auto tens = array<string, 10>
{
    "zero",
    "ten",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
};

const static auto hundred = "hundred";

const static auto orders = vector<string>
{
    "thousand",
    "million",
    "billion",
    "trillion",
    "quadrillion",
    "quintillion",
    "sextillion",
    "septillion",
    "octillion",
    "nonillion",
    "decillion",
    "undecillion",
    "duodecillion",
    "tredecillion",
    "quattuordecillion",
    "quindecillion",
    "sexdecillion",
    "septendecillion",
    "octodecillion",
    "novemdecillion",
    "vigintillion"
};

template<typename T>
static string get_name(const T num)
{
    if(num == 0)
    {
        return ones[0];
    }
    auto ord = 0;
    auto num2 = num;
    while(num2 >= 1000)
    {
        num2 /= 1000;
        ord++;
    }
    stringstream ss;
    while(ord >= 0)
    {
        auto ord_num = num;
        for (auto i = 0; i < ord; i++)
        {
            ord_num /= 1000;
        }
        ord_num %= 1000;
        //const auto ord_num = num % 1000;
        const auto hundr_num = static_cast<size_t>(ord_num % 100);
        const auto hundreds = static_cast<size_t>(ord_num / 100);
        const auto tens_num = static_cast<size_t>(hundr_num / 10);
        const auto ones_num = static_cast<size_t>(hundr_num % 10);
        if(hundreds > 0)
        {
            ss << ones[hundreds] << " " << hundred << " ";
            if (hundr_num > 0)
            {
                ss << "and ";
            }
        }
        if (tens_num > 1)
        {
            ss << tens[tens_num];
            if (ones_num > 0)
            {
                ss << "-" << ones[ones_num];
            }
            ss << " ";
        }
        else if (tens_num == 1)
        {
            ss << teens[ones_num] << " ";
        }
        else if (ones_num > 0)
        {
            ss << ones[ones_num] << " ";
        }
        if(ord > 0)
        {
            ss << orders[ord-1] << " ";
        }
        //num /= 1000;
        ord--;
    }
    auto str = ss.str();
    str.erase(str.end() - 1);
    return str;
}

int64_t impl_17_1::solve()
{
    auto sum = 0;
    for (auto i = 1; i <= 1000; i++)
    {
        auto str = get_name(i);
        for (auto ch : str)
        {
            if (ch == ' ' || ch == '-')
            {
                continue;
            }
            sum++;
        }
    }
    return sum;
}