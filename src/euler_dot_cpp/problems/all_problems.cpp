#include "stdafx.hpp"
#include "all_problems.hpp"

#include "1_9/problem_1.hpp"
#include "1_9/problem_2.hpp"
#include "1_9/problem_3.hpp"
#include "1_9/problem_4.hpp"
#include "1_9/problem_5.hpp"
#include "1_9/problem_6.hpp"
#include "1_9/problem_7.hpp"
#include "1_9/problem_8.hpp"
#include "1_9/problem_9.hpp"

#include "10_19/problem_10.hpp"
#include "10_19/problem_11.hpp"
#include "10_19/problem_12.hpp"
#include "10_19/problem_13.hpp"
#include "10_19/problem_14.hpp"
#include "10_19/problem_15.hpp"
#include "10_19/problem_16.hpp"
#include "10_19/problem_17.hpp"
#include "10_19/problem_18.hpp"
#include "10_19/problem_19.hpp"

#include "20_29/problem_20.hpp"
#include "20_29/problem_21.hpp"
#include "20_29/problem_22.hpp"
#include "20_29/problem_23.hpp"
#include "20_29/problem_24.hpp"
#include "20_29/problem_25.hpp"
#include "20_29/problem_26.hpp"
#include "20_29/problem_27.hpp"
#include "20_29/problem_28.hpp"
#include "20_29/problem_29.hpp"

#include "30_39/problem_30.hpp"
#include "30_39/problem_31.hpp"
#include "30_39/problem_32.hpp"
#include "30_39/problem_33.hpp"
#include "30_39/problem_34.hpp"
#include "30_39/problem_35.hpp"
#include "30_39/problem_36.hpp"
#include "30_39/problem_37.hpp"
#include "30_39/problem_38.hpp"
#include "30_39/problem_39.hpp"

#include "40_49/problem_40.hpp"
#include "40_49/problem_41.hpp"
#include "40_49/problem_42.hpp"
#include "40_49/problem_43.hpp"
#include "40_49/problem_44.hpp"
#include "40_49/problem_45.hpp"
#include "40_49/problem_46.hpp"
#include "40_49/problem_47.hpp"
#include "40_49/problem_48.hpp"

#include "60_69/problem_62.hpp"
#include "60_69/problem_67.hpp"

#include "90_99/problem_94.hpp"

using namespace std;

void init_problems(problems_map& problems)
{
    auto ptr_vec = vector<unique_ptr<problem>>();

    ptr_vec.emplace_back(make_unique<problem_1>());
    ptr_vec.emplace_back(make_unique<problem_2>());
    ptr_vec.emplace_back(make_unique<problem_3>());
    ptr_vec.emplace_back(make_unique<problem_4>());
    ptr_vec.emplace_back(make_unique<problem_5>());
    ptr_vec.emplace_back(make_unique<problem_6>());
    ptr_vec.emplace_back(make_unique<problem_7>());
    ptr_vec.emplace_back(make_unique<problem_8>());
    ptr_vec.emplace_back(make_unique<problem_9>());

    ptr_vec.emplace_back(make_unique<problem_10>());
    ptr_vec.emplace_back(make_unique<problem_11>());
    ptr_vec.emplace_back(make_unique<problem_12>());
    ptr_vec.emplace_back(make_unique<problem_13>());
    ptr_vec.emplace_back(make_unique<problem_14>());
    ptr_vec.emplace_back(make_unique<problem_15>());
    ptr_vec.emplace_back(make_unique<problem_16>());
    ptr_vec.emplace_back(make_unique<problem_17>());
    ptr_vec.emplace_back(make_unique<problem_18>());
    ptr_vec.emplace_back(make_unique<problem_19>());

    ptr_vec.emplace_back(make_unique<problem_20>());
    ptr_vec.emplace_back(make_unique<problem_21>());
    ptr_vec.emplace_back(make_unique<problem_22>());
    ptr_vec.emplace_back(make_unique<problem_23>());
    ptr_vec.emplace_back(make_unique<problem_24>());
    ptr_vec.emplace_back(make_unique<problem_25>());
    ptr_vec.emplace_back(make_unique<problem_26>());
    ptr_vec.emplace_back(make_unique<problem_27>());
    ptr_vec.emplace_back(make_unique<problem_28>());
    ptr_vec.emplace_back(make_unique<problem_29>());

    ptr_vec.emplace_back(make_unique<problem_30>());
    ptr_vec.emplace_back(make_unique<problem_31>());
    ptr_vec.emplace_back(make_unique<problem_32>());
    ptr_vec.emplace_back(make_unique<problem_33>());
    ptr_vec.emplace_back(make_unique<problem_34>());
    ptr_vec.emplace_back(make_unique<problem_35>());
    ptr_vec.emplace_back(make_unique<problem_36>());
    ptr_vec.emplace_back(make_unique<problem_37>());
    ptr_vec.emplace_back(make_unique<problem_38>());
    ptr_vec.emplace_back(make_unique<problem_39>());

    ptr_vec.emplace_back(make_unique<problem_40>());
    ptr_vec.emplace_back(make_unique<problem_41>());
    ptr_vec.emplace_back(make_unique<problem_42>());
    ptr_vec.emplace_back(make_unique<problem_43>());
    ptr_vec.emplace_back(make_unique<problem_44>());
    ptr_vec.emplace_back(make_unique<problem_45>());
    ptr_vec.emplace_back(make_unique<problem_46>());
    ptr_vec.emplace_back(make_unique<problem_47>());
    ptr_vec.emplace_back(make_unique<problem_48>());
    
    ptr_vec.emplace_back(make_unique<problem_62>());
    ptr_vec.emplace_back(make_unique<problem_67>());

    ptr_vec.emplace_back(make_unique<problem_94>());

    for (auto& ptr : ptr_vec)
    {
        if (problems.find(ptr->id) != problems.end())
        {
            cout << "Duplicate problem added";
            throw std::exception();
        }
        problems[ptr->id] = std::move(ptr);
    }
}