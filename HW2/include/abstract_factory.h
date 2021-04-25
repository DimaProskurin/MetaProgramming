#ifndef METAPROGRAMMING_ABSTRACT_FACTORY_H
#define METAPROGRAMMING_ABSTRACT_FACTORY_H

#include "hierarchy_scatter.h"
#include "hierarchy_linear.h"
#include "allocator.h"
#include <memory>

template<typename T>
struct TypeDescriptor {};

template<typename T>
struct IAbstractFactoryUnit {
    virtual T *create(TypeDescriptor<T>) = 0;

    virtual ~IAbstractFactoryUnit() {}
};

template<typename TypeList>
struct IAbstractFactory : GenScatterHierarchy<TypeList, IAbstractFactoryUnit> {
    template<typename T>
    T *create() {
        T* t_ptr = new T;
        return t_ptr;
    }
};

template<
        template<typename T, template<typename> typename Allocator> typename FactoryUnit,
        template<typename> typename Allocator,
        typename T,
        typename Base
>
struct FactoryUnitWrapper : FactoryUnit<T, Allocator>, Base {
    virtual T *create(TypeDescriptor<T>) {
        return FactoryUnit<T, Allocator>::create(allocator);
    }

private:
    Allocator<T> allocator;
};

template<
        template<typename T, template<typename> typename Allocator> typename FactoryUnit,
        template<typename> typename Allocator
>
struct GetFactoryUnitWrapper {
    template<typename T, typename Base>
    using FactoryUnitWrapperAlias = FactoryUnitWrapper<FactoryUnit, Allocator, T, Base>;
};

template<
        typename TypeList,
        template<typename, template<typename> typename> typename FactoryUnit,
        template<typename> typename Allocator
>
using CAbstractFactory = GenLinearHierarchy<
        TypeList,
        GetFactoryUnitWrapper<FactoryUnit, Allocator>::template FactoryUnitWrapperAlias,
        IAbstractFactory<TypeList>
>;

#endif //METAPROGRAMMING_ABSTRACT_FACTORY_H
