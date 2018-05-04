#include "stdafx.hpp"
#include "problem_31.hpp"

using namespace std;

static class coin_detail
{
public:
    explicit coin_detail(int64_t value) : value(value)
    {
    }

    int64_t value = 0;
    int64_t combinations = 0;
};

int64_t impl_31_1::solve()
{
    // broken;
    return -1;
    vector<coin_detail> coins;
    coins.emplace_back(1);
    coins.emplace_back(2);
    coins.emplace_back(5);

    coins[0].combinations = 1;

    for(auto i = 1; i < coins.size(); ++i)
    {
        auto& coin = coins[i];
        vector<coin_detail> composite_coins;
        auto remaining_value = coin.value;
        while(remaining_value > 0)
        {
            for (auto j = i-1; j >= 0; --j)
            {
                auto& composite_coin = coins[j];
                if(remaining_value - composite_coin.value >= 0)
                {
                    remaining_value -= composite_coin.value;
                    composite_coins.push_back(composite_coin);
                    break;
                }
            }
        }

        coin.combinations = 1;
        for(auto& composite : composite_coins)
        {
            coin.combinations *= composite.combinations;
        }

        coin.combinations++; // A coin can be made from itself
    }

	return 0;
}

int64_t impl_31_2::solve()
{
    int64_t target = 200;
    int64_t ways = 0;

    for (int64_t a = target; a >= 0; a -= 200) {
        for (int64_t b = a; b >= 0; b -= 100) {
            for (int64_t c = b; c >= 0; c -= 50) {
                for (int64_t d = c; d >= 0; d -= 20) {
                    for (int64_t e = d; e >= 0; e -= 10) {
                        for (int64_t f = e; f >= 0; f -= 5) {
                            for (int64_t g = f; g >= 0; g -= 2) {
                                ways++;
                            }
                        }
                    }
                }
            }
        }
    }

    return ways;
}

int64_t impl_31_3::solve()
{
    constexpr int64_t target = 200;
    const array<int64_t, 8> coins { 1, 2, 5, 10, 20, 50, 100, 200 };
    array<int64_t, target + 1> cache;
    std::fill(cache.begin(), cache.end(), 0);
    cache[0] = 1; // 1 way to make 0 cents

    for (int32_t i = 0; i < coins.size(); i++)
    {
        for (int64_t j = coins[i]; j <= target; j++)
        {
            cache[j] += cache[j - coins[i]];
        }
    }

    return cache[target];
}
