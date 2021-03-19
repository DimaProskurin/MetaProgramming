#include "../include/test_erase.h"
#include "../../TypeList.h"

TEST_F(EraseTestCase, EraseEmpty) {
    using EmptyList = TypeListBuilder<>::Result;
    bool res = std::is_same<Erase<EmptyList, int>::Result, EmptyList>::value;
    EXPECT_TRUE(res);
};

TEST_F(EraseTestCase, EraseFirst) {
    using List = TypeListBuilder<char, int, float>::Result;
    using Correct = TypeListBuilder<int, float>::Result;
    bool res = std::is_same<Erase<List, char>::Result, Correct>::value;
    EXPECT_TRUE(res);
};

TEST_F(EraseTestCase, EraseLast) {
    using List = TypeListBuilder<char, int, float>::Result;
    using Correct = TypeListBuilder<char, int>::Result;
    bool res = std::is_same<Erase<List, float>::Result, Correct>::value;
    EXPECT_TRUE(res);
};

TEST_F(EraseTestCase, EraseMiddle) {
    using List = TypeListBuilder<char, int, float>::Result;
    using Correct = TypeListBuilder<char, float>::Result;
    bool res = std::is_same<Erase<List, int>::Result, Correct>::value;
    EXPECT_TRUE(res);
};
