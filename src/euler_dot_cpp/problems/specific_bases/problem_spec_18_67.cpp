#include "stdafx.hpp"
#include "problem_spec_18_67.hpp"

#include "../../common/io.hpp"

using namespace std;

void impl_spec_18_67_1::reinit()
{
	auto& pr = static_cast<problem_spec_18_67&>(*prblm);
	tree = pr.tree_orig;
}

int64_t impl_spec_18_67_1::solve()
{
	auto& data = tree;
	for (auto i = static_cast<int32_t>(data.size() - 2); i >= 0; --i)
	{
		auto& row = data[i];
		auto& nextrow = data[i+1];
		for (auto j = 0; j <= i; j++)
		{
			const auto max_child = max(nextrow[j], nextrow[j + 1]);
			row[j] += max_child;
		}
	}
	return data[0][0];
}

void impl_spec_18_67_2::init()
{
	auto& pr = static_cast<problem_spec_18_67&>(*prblm);
	for (auto i = 0; i < pr.tree_orig.size(); i++)
	{
		for (auto j = 0; j <= i; j++)
		{
			mtrx_orig[i][j] = pr.tree_orig[i][j];
		}
	}
}

void impl_spec_18_67_2::reinit()
{
	mtrx = mtrx_orig;
}

int64_t impl_spec_18_67_2::solve()
{
	auto& data = mtrx;
	for (auto i = static_cast<int32_t>(data.size() - 2); i >= 0; --i)
	{
		auto& row = data[i];
		auto& nextrow = data[i + 1];
		for (auto j = 0; j <= i; j++)
		{
			const auto max_child = max(nextrow[j], nextrow[j + 1]);
			row[j] += max_child;
		}
	}
	return data[0][0];
}

void problem_spec_18_67::init()
{
    const auto path = get_input_path();
    tree_orig = read_matrix<data_t>(path);
}