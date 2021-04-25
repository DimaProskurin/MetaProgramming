#ifndef METAPROGRAMMING_ALLOCATOR_H
#define METAPROGRAMMING_ALLOCATOR_H

template<typename T>
struct IAllocator {
    virtual T *allocate() = 0;

    virtual ~IAllocator() {}
};

template<typename T>
struct AllocatorUsingNew : public IAllocator<T> {
    virtual T *allocate() {
        return new T();
    }
};

#endif //METAPROGRAMMING_ALLOCATOR_H
