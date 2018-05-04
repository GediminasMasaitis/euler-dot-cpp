#pragma once 
#include "../problem_base.h"

class impl_$p_1 : public problem_impl_base
{
public:
	int64_t solve() override;
};


class problem_$p : public problem
{
public:
	problem_$p()
	{
		id = $p;
		name = "";
		answer = 0;
        difficulty = 5;
        solved = false;

        add_impl<impl_$p_1>();
	}
};
