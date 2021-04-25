#include "../include/abstract_factory.h"

struct Infantry {};
struct Archer {};
struct Cavalry {};
using UnitsList = TypeListBuilder<Infantry, Archer, Cavalry>::Result;

template<typename T, template<typename> typename Allocator>
struct FactoryUnit {
    T *create(Allocator<T> &allocator) {
        return allocator.allocate();
    }
};

using IArmyFactory = IAbstractFactory<UnitsList>;
using CArmyFactory = CAbstractFactory<UnitsList, FactoryUnit, AllocatorUsingNew>;

int main() {
    IArmyFactory *factory = new CArmyFactory();
    Archer* archer = factory->create<Archer>();
    Cavalry* cavalry = factory->create<Cavalry>();
    Infantry* infantry = factory->create<Infantry>();
    return 0;
}