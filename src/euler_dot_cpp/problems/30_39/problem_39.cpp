#include "stdafx.hpp"
#include "problem_39.hpp"
#include "../../common/pythagoras.hpp"

using namespace std;

int64_t impl_39_1::solve()
{
    constexpr int64_t limit = 1001;
    google::dense_hash_map<int64_t, size_t> counts;
    counts.set_deleted_key(-1);
    counts.set_empty_key(-2);

    pythagorean_triplets_unique_old<int64_t>(limit, [&counts](const pythagorean_triplet<int64_t>& trip)
    {
        counts[trip.sum]++;
        return true;
    });

    int64_t max_num = -1;
    size_t max_val = 0;
    for (auto&& pair : counts)
    {
        if(pair.second > max_val)
        {
            max_num = pair.first;
            max_val = pair.second;
        }
    }

	return max_num;
}

int64_t impl_39_2::solve()
{
    constexpr int64_t limit = 1001;
    google::dense_hash_map<int64_t, size_t> counts;
    counts.set_deleted_key(-1);
    counts.set_empty_key(-2);

    pythagorean_triplets_all<int64_t>(limit, [&counts](const pythagorean_triplet<int64_t>& trip)
    {
        counts[trip.sum]++;
        return true;
    });

    int64_t max_num = -1;
    size_t max_val = 0;
    for (auto&& pair : counts)
    {
        if (pair.second > max_val)
        {
            max_num = pair.first;
            max_val = pair.second;
        }
    }

    return max_num;
}

int64_t impl_39_3::solve()
{
    constexpr int64_t limit = 1001;
    std::array<size_t, limit> counts{};

    pythagorean_triplets_all<int64_t>(limit, [&counts](const pythagorean_triplet<int64_t>& trip)
    {
        counts[trip.sum]++;
        return true;
    });

    int64_t max_num = -1;
    int64_t max_val = 0;
    for (auto i = 1; i < limit; i++)
    {
        if (counts[i] > max_val)
        {
            max_num = i;
            max_val = counts[i];
        }
    }

    return max_num;
}
