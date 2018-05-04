#pragma once

template
<
    typename TValue,
    typename TIndex,
    typename TState
>
class generator_base
{
public:
    const TIndex from;
    const TIndex to;
    const TState initial_state;

    constexpr generator_base(const TIndex from, const TIndex to, const TState initial_state) : from(from), to(to), initial_state(initial_state)
    {
    }
};

template
<
    typename TValue,
    typename TIndex,
    TIndex VFrom,
    TIndex VTo
>
class number_sequence_base
{
public:
    using value_t = TValue;
    using index_t = TIndex;

    static constexpr size_t static_size()
    {
        return static_cast<size_t>(VTo - VFrom);
    }

    value_t values[static_size()];

    constexpr number_sequence_base() : values()
    {
    }

    constexpr size_t size()
    {
        return static_size();
    }
};

template
<
    typename TValue,
    typename TIndex,
    TIndex VFrom,
    TIndex VTo
>
class generator_sequence : public number_sequence_base<TValue, TIndex, VFrom, VTo>
{
public:
    template<typename TGenerator>
    constexpr generator_sequence(TGenerator generator) : number_sequence_base<TValue, TIndex, VFrom, VTo>()
    {
        //TGenerator generator(VFrom, VTo);
        auto state = generator.initial_state;
        for (size_t i = 0; i < this->size(); ++i)
        {
            this->values[i] = generator(i, state);
        }
    }
};

template
<
    typename TValue,
    typename TIndex,
    typename TGenerator,
    TIndex VFrom,
    TIndex VTo
>
class generator_sequence_templ : public generator_sequence<TValue, TIndex, VFrom, VTo>
{
public:
    constexpr generator_sequence_templ() : generator_sequence<TValue, TIndex, VFrom, VTo>(TGenerator(VFrom, VTo))
    {
    }
};

template
<
    typename TValue,
    typename TIndex
>
class stateless_generator : public generator_base<TValue, TIndex, void*>
{
public:
    constexpr stateless_generator(const TIndex& from, const TIndex& to) : generator_base<TValue, TIndex, void*>(from, to, nullptr)
    {
    }
};

template
<
    typename TValue,
    typename TIndex
>
class transform_generator : public generator_base<TValue, TIndex, TIndex>
{
public:
    constexpr transform_generator(const TIndex& from, const TIndex& to) : generator_base<TValue, TIndex, TIndex>(from, to, from)
    {
    }

    template<typename TTransform>
    constexpr TValue operator()(TIndex index, void*) const
    {
        return 2;
    }
};

template
<
    typename TValue,
    typename TIndex,
    TIndex VFrom,
    TIndex VTo
>
class transform_sequence : public number_sequence_base<TValue, TIndex, VFrom, VTo>
{
public:
    template<typename TTransform>
    explicit constexpr transform_sequence(TTransform transform) : number_sequence_base<TValue, TIndex, VFrom, VTo>()
    {
        TIndex index = VFrom;
        for (size_t i = 0; i < this->size(); ++i)
        {
            this->values[i] = transform(index++);
        }
    }
};

template
<
    typename TValue,
    typename TIndex,
    TIndex VFrom,
    TIndex VTo,
    TValue(*VTransform)(TIndex)
>
class transform_sequence_templ : public transform_sequence<TValue, TIndex, VFrom, VTo>
{
public:
    constexpr transform_sequence_templ() : transform_sequence<TValue, TIndex, VFrom, VTo>(VTransform)
    {
    }
};