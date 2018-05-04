#include "stdafx.hpp"
#include "problem_11.hpp"
#include "../../common/io.hpp"

using namespace std;

int64_t impl_11_1::solve()
{
    auto& pr = static_cast<problem_11&>(*prblm);
    auto& data = pr.data;
    const auto num = 4;
    const auto size = data.size();
    uint64_t max = 0;
    for(auto i = 0; i < size; i++)
    {
        for (auto j = 0; j < size; j++)
        {
            uint64_t prod_vert = 1;
            uint64_t prod_hor = 1;
            uint64_t prod_diag = 1;
            uint64_t prod_antidiag = 1;
            for (auto k = 0; k < num; k++)
            {
                if(i < size && j + k < size)
                {
                    prod_vert *= data[i][j + k];
                }

                if (i + k < size && j < size)
                {
                    prod_hor *= data[i+k][j];
                }

                if (i + k < size && j + k < size)
                {
                    prod_diag *= data[i+k][j + k];
                }
                
                auto idx = i + num - 1 - k;
                if (idx < size && j + k < size)
                {
                    prod_antidiag *= data[idx][j+k];
                }
            }
            if(prod_vert > max)
            {
                max = prod_vert;
            }
            if (prod_hor > max)
            {
                max = prod_hor;
            }
            if (prod_diag > max)
            {
                max = prod_diag;
            }
            if (prod_antidiag > max)
            {
                max = prod_antidiag;
            }
        }
    }
    return max;
}

void problem_11::init()
{
    data = read_matrix<data_t>("p011_matrix.txt");
}
