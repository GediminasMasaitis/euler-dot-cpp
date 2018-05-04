#pragma once

template<typename TIndex, typename TNum>
void fibonacci_numbers(std::function<bool(TIndex, TNum)> act)
{
    TNum prev = 0;
    TNum num = 1;
    for (TIndex i = 0;; ++i)
    {
        if (!act(i, num))
        {
            return;
        }
        const auto temp = num;
        num += prev;
        prev = temp;
    }
}