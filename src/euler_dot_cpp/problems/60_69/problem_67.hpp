#pragma once
#include "../problem_base.hpp"
#include "../specific_bases/problem_spec_18_67.hpp"

class problem_67 : public problem_spec_18_67
{
public:
	using data_t = uint64_t;
	std::vector<std::vector<data_t>> tree_orig;

	problem_67()
	{
		id = 67;
		name = "Maximum path sum II";
		answer = 7273;
        difficulty = 5;
        solved = true;
	}

    std::string get_input_path() override;
};
