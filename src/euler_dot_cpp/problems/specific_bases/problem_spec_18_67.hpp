#pragma once
#include "../problem_base.hpp"

class impl_spec_18_67_1 : public problem_impl_base
{
public:
    impl_spec_18_67_1()
    {
        requires_reinit = true;
    }
	void reinit() override;
	int64_t solve() override;
private:
	using data_t = uint64_t;
	std::vector<std::vector<data_t>> tree;
};

class impl_spec_18_67_2 : public problem_impl_base
{
public:
    impl_spec_18_67_2()
    {
        requires_reinit = true;
    }
	void init() override;
	void reinit() override;
	int64_t solve() override;
private:
	using data_t = uint64_t;
	using mtrx_t = std::array<std::array<data_t, 100>, 100>;
	mtrx_t mtrx_orig;
	mtrx_t mtrx;
};

class problem_spec_18_67 : public problem
{
public:
	using data_t = uint64_t;
	std::vector<std::vector<data_t>> tree_orig;

    problem_spec_18_67()
	{
        add_impl<impl_spec_18_67_1>();
        add_impl<impl_spec_18_67_2>();
	}

    virtual std::string get_input_path() = 0;// = "p018_triangle.txt";

	void init() override;
};
