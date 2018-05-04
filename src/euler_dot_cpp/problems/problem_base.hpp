#pragma once
#include "../stdafx.hpp"

class problem;

class problem_impl_base
{
public:
    bool requires_reinit = false;
	problem* prblm;

	virtual void init() {}
	virtual void reinit() {}
	virtual int64_t solve() = 0;
};

class problem
{
public:
	int32_t id;
	std::string name;
	int64_t answer;
    uint32_t difficulty;
    bool solved;
    
    bool requires_reinit = false;
	std::vector<std::unique_ptr<problem_impl_base>> impls;

	virtual void init() {}
	virtual void reinit() {}

	virtual int64_t solve(const int impl_idx = 0)
	{
		return impls[impl_idx]->solve();
	}

protected:
	template<typename T, typename... V>
	void add_impl(V&&... args)
	{
		impls.push_back(std::make_unique<T>(std::forward<V>(args)...));
		impls.back()->prblm = this;
	}
};

