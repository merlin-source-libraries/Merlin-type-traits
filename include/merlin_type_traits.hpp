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
    struct is_strict_integral : public type_disjunction<typename std::remove_cv<T>::type, short    , unsigned short,
                                                                                          int      , unsigned int,
                                                                                          long     , unsigned long,
                                                                                          long long, unsigned long long>
    {};

    template <typename ... Ts>
    struct variadic
    {
        template <typename ... Us>
        static constexpr bool is_same()
        {
            if constexpr ((sizeof...(Ts) == sizeof...(Us)))
            {
                return (std::is_same<Ts, Us>::value && ...);
            }
            else
                return false;
        }
    };
}

#endif
