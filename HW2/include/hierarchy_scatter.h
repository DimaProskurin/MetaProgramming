#ifndef METAPROGRAMMING_HIERARCHY_SCATTER_H
#define METAPROGRAMMING_HIERARCHY_SCATTER_H

#include "../../HW1/TypeList.h"

template<typename TypeList, template<typename AtomicType> typename Unit>
struct GenScatterHierarchy;

template<typename ... Types, template<typename> typename Unit>
struct GenScatterHierarchy<TypeList<Types...>, Unit> : public Unit<Types> ... {};

#endif //METAPROGRAMMING_HIERARCHY_SCATTER_H
