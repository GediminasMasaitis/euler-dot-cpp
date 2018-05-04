#include "stdafx.hpp"
#include "problem_13.hpp"

#include "../../common/prec.hpp"
#include "../../common/io.hpp"

using namespace std;
using namespace boost;

static uint64_t get_answer_from_str(const string& str)
{
    const auto head = str.substr(0, 10);
    const auto num = stoull(head);
    return num;
}

int64_t impl_13_1::solve()
{
    auto& pr = static_cast<problem_13&>(*prblm);
    big_int sum;
    for(const auto& str : pr.data)
    {
        auto bi = big_int(str);
        sum += bi;
        sum.shrink();
    }
	return 0;
}

int64_t impl_13_2::solve()
{
    auto& pr = static_cast<problem_13&>(*prblm);

    const auto len = static_cast<int32_t>(pr.data[0].size());
    auto carry = 0;
    stringstream ss;
    for (int i = len; i >= 0; --i)
    {
        auto sum = 0;
        for (const auto& str : pr.data)
        {
            sum += str[i] - 0x30;
        }
        sum += carry;
        ss << sum % 10;
        carry = sum / 10;
    }
    while (carry != 0)
    {
        ss << carry % 10;
        carry /= 10;
    }
    auto str = ss.str();
    reverse(str.begin(), str.end());
    return get_answer_from_str(str);
}

int64_t impl_13_3::solve()
{
    auto& pr = static_cast<problem_13&>(*prblm);
    multiprecision::cpp_int sum;
    for (const auto& str : pr.data)
    {
        const auto num = multiprecision::cpp_int(str);
        sum += num;
    }
    const auto str = sum.str();
    return get_answer_from_str(str);
}

int64_t impl_13_4::solve()
{
    auto& pr = static_cast<problem_13&>(*prblm);
    multiprecision::uint256_t sum;
    for (const auto& str : pr.data)
    {
        const auto num = multiprecision::uint256_t(str);
        sum += num;
    }
    const auto str = sum.str();
    return get_answer_from_str(str);
}

void problem_13::init()
{
    data = read_all_lines("p013_numbers.txt");
}
