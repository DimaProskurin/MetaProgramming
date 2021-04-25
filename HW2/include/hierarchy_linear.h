#ifndef METAPROGRAMMING_HIERARCHY_LINEAR_H
#define METAPROGRAMMING_HIERARCHY_LINEAR_H

#include "../../HW1/TypeList.h"

template<typename TypeList, template<typename AtomicType, typename BaseType> typename Unit, typename Root = NullType>
struct GenLinearHierarchy;

template<typename T1, typename ... T2, template<typename AtomicType, typename BaseType> typename Unit, typename Root>
struct GenLinearHierarchy<TypeList<T1, T2...>, Unit, Root>
        : public Unit<T1, GenLinearHierarchy<TypeList<T2..., NullType>, Unit, Root>> {
};

template<typename T, template<typename, typename> typename Unit, typename Root>
struct GenLinearHierarchy<TypeList<T, NullType>, Unit, Root> : public Unit<T, Root> {};

#endif //METAPROGRAMMING_HIERARCHY_LINEAR_H
