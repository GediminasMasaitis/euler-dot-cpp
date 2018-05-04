#pragma once

// Algorithm result and control predicate functions
template<typename TNum>
using alg_res_pred = std::function<bool(TNum)>;

template<typename TNum>
using alg_res_ref_pred = std::function<bool(const TNum&)>;

template<typename TIndex, typename TNum>
using alg_idx_res_pred = std::function<bool(TIndex, TNum)>;

template<typename TIndex, typename TNum>
using alg_idx_res_ref_pred = std::function<bool(TIndex, const TNum&)>;