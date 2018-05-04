#include "stdafx.hpp"
#include "problem_28.hpp"

using namespace std;

template<size_t TSize>
static void visualize_spiral(array<array<uint64_t, TSize>, TSize>& spiral)
{
    stringstream ss;
    ss << endl;
    for (auto i = 0; i < TSize; i++)
    {
        for (auto j = 0; j < TSize; j++)
        {
            ss << setw(2) << spiral[j][i] << " ";
        }
        ss << endl;
    }
    ss << endl;
    cout << ss.str();
}

int64_t impl_28_1::solve()
{
    static constexpr size_t spiral_size = 1001;
    constexpr size_t mid = spiral_size/2;
    const auto spiral_ptr = make_unique<array<array<uint64_t, spiral_size>, spiral_size>>();
    auto& spiral = *spiral_ptr;
    for (auto i = 0; i < spiral_size; i++)
    {
        std::fill(spiral[i].begin(), spiral[i].end(), 0);
    }
    spiral[mid][mid] = 1;
    uint64_t num = 1;
    for (auto ring = 1; ring <= mid; ring++)
    {
        const auto side_len = ring * 2;

        for (auto i = 0; i < side_len; i++)
        {
            spiral[mid + ring][mid - ring + 1 + i] = ++num;
        }

        for (auto i = 0; i < side_len; i++)
        {
            spiral[mid + ring - 1 - i][mid + ring] = ++num;
        }

        for (auto i = 0; i < side_len; i++)
        {
            spiral[mid - ring][mid + ring - 1 - i] = ++num;
        }

        for (auto i = 0; i < side_len; i++)
        {
            spiral[mid - ring + 1 + i][mid - ring] = ++num;
        }
    }
    uint64_t sum = 0;
    for (auto i = 0; i < spiral_size; i++)
    {
        sum += spiral[i][i];
        sum += spiral[spiral_size - 1 - i][i];
    }
    sum -= spiral[mid][mid];
    return sum;
}

int64_t impl_28_2::solve()
{
    static constexpr size_t spiral_size = 1001;
    constexpr size_t mid = spiral_size / 2;
    uint64_t sum = 1;
    uint64_t num = 1;
    for (auto ring = 1; ring <= mid; ring++)
    {
        const auto side_len = ring * 2;
        for (auto i = 0; i < 4; i++)
        {
            num += side_len;
            sum += num;
        }
    }
    return sum;
}
