#ifndef MERLIN_TYPE_TRAITS_HPP
#define MERLIN_TYPE_TRAITS_HPP

#include <type_traits>

namespace merl
{
    template <typename T, typename ... Ts>
    struct type_disjunction
    {
        constexpr static bool value = std::disjunction<std::is_same<T, Ts>...>::value;
    };

    template <typename T>
    struct is_strict_integral : public type_disjunction<T, short    , unsigned short,
                                                           int      , unsigned int,
                                                           long     , unsigned long,
                                                           long long, unsigned long long>
    {};
}

#endif
