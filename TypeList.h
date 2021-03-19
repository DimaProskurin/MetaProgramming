class NullType {};

template<typename T, typename U>
struct TypeList {
    typedef T Head;
    typedef U Tail;
};

// Creation
template<typename... Ts>
struct TypeListBuilder {
    using Result = NullType;
};

template<typename T, typename... Ts>
struct TypeListBuilder<T, Ts...> {
    using Result = TypeList<T, typename TypeListBuilder<Ts...>::Result>;
};


// Length
template<typename TList> struct Length;
template<> struct Length<NullType> {
    enum { value = 0 };
};

template<typename T, typename U>
struct Length< TypeList<T, U> > {
    enum { value = 1 + Length<U>::value };
};


// TypeAt
template<typename TList, unsigned int index> struct TypeAt;

template<typename Head, typename Tail>
struct TypeAt<TypeList<Head, Tail>, 0> {
    using Result = Head;
};

template<typename Head, typename Tail, unsigned int i>
struct TypeAt<TypeList<Head, Tail>, i> {
    using Result = typename TypeAt<Tail, i - 1>::Result;
};


// Erase
template<typename TList, typename T> struct Erase;

template<typename T>
struct Erase<NullType, T> {
    using Result = NullType;
};

template<typename T, typename Tail>
struct Erase<TypeList<T, Tail>, T> {
    using Result = Tail;
};

template<typename Head, typename Tail, typename T>
struct Erase<TypeList<Head, Tail>, T> {
    using Result = TypeList<Head, typename Erase<Tail, T>::Result>;
};
