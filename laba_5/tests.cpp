#include <gtest/gtest.h>
#include "list.hpp"
#include "perfect_allocator.hpp"

TEST(Test_List, constructors) {
    List<int> a;
    ASSERT_EQ(a.size(), 0);

    List<int> b(4, 3);
    ASSERT_EQ(b.size(), 4);
    for (int elem : b) {
        ASSERT_EQ(elem, 3);
    }

    List<int> c(4);
    ASSERT_EQ(c.size(), 4);
    for (int elem : c) {
        ASSERT_EQ(elem, 0);
    }

    List<int> d {1, 2, 3, 4, 5};
    ASSERT_EQ(d.size(), 5);
    {int i = 1;
    for (int elem : d) {
        ASSERT_EQ(elem, i++);
    }
    }

    List<int> e(d);
    ASSERT_EQ(e.size(), 5);
    {int i = 1;
    for (int elem : e) {
        ASSERT_EQ(elem, i++);
    }
    }

    List<int> f(List<int>(3));
    ASSERT_EQ(f.size(), 3);
    for (int elem : f) {
        ASSERT_EQ(elem, 0);
    }

}

TEST(Test_List, push_back) {
    List<int> a;
    a.push_back(4);
    ASSERT_EQ(a.size(), 1);
    for (int elem : a) {
        ASSERT_EQ(elem, 4);
    }

    List<int> b {1, 2, 3};
    b.push_back(4);
    ASSERT_EQ(b.size(), 4);
    {int i = 1;
    for (int elem : b) {
        ASSERT_EQ(elem, i++);
    }
    }
}

TEST(Test_List, pop_back) {
    List<int> a;
    ASSERT_ANY_THROW(a.pop_back());

    List<int> b(1, 0);
    b.pop_back();
    ASSERT_EQ(b.size(), 0);
    b.push_back(1);
    ASSERT_EQ(b.size(), 1);
    ASSERT_EQ(*b.begin(), 1);

    List<int> c {1, 2, 3};
    c.pop_back();
    ASSERT_EQ(c.size(), 2);
    {int i = 1;
    for (int elem : c) {
        ASSERT_EQ(elem, i++);
    }
    }
}

TEST(Test_List, insert) {
    List<int> a;
    a.insert(a.begin(), 1);
    ASSERT_EQ(a.size(), 1);
    ASSERT_EQ(*a.cbegin(), 1);
    ASSERT_EQ(*(--a.cend()), 1);

    List<int> b(1, 0);
    b.insert(b.end(), 1);
    ASSERT_EQ(b.size(), 2);
    ASSERT_EQ(*(--b.cend()), 1);

    List<int> c{1, 3, 4};
    {auto itr = ++c.begin();
    c.insert(itr, 2);
    int i = 1;
    for (int elem : c) {
        ASSERT_EQ(elem, i++);
    }
    }
}

TEST(Test_List, erase) {
    List<int> a;
    ASSERT_ANY_THROW(a.erase(a.begin()));

    List<int> b(1);
    b.erase(b.begin());
    ASSERT_EQ(b.size(), 0);

    List<int> c {1, 2, 1};
    {auto itr = --c.end();
    c.erase(itr);
    int i = 1;
    for (int elem : c) {
        ASSERT_EQ(elem, i++);
    }
    }

    List<int> d {1, 2, 2, 3, 4};
    {auto itr = std::next(d.begin(), 2);
    d.erase(itr);
    int i = 1;
    for (int elem : d) {
        ASSERT_EQ(elem, i++);
    }
    }
}

TEST(Test_List, operators) {
    List<int> a {1, 2, 3}, b{5, 4, 3, 2, 1};
    a = List(4, 5);
    ASSERT_EQ(a.size(), 4);
    for (int elem : a) {
        ASSERT_EQ(elem, 5);
    }

    b = a;
    ASSERT_EQ(b.size(), 4);
    for (int elem : b) {
        ASSERT_EQ(elem, 5);
    }

}

TEST(Test_Allocator, numerous_allocation) {
    Reserve_Allocator<int, 100> alloc;
    ASSERT_ANY_THROW(alloc.allocate(101));
    int* arr1 = alloc.allocate(4); 
    int* arr2 = alloc.allocate(2);
    for (int i = 0; i < 4; ++i) {
        arr1[i] = i;
    }
    for (int i = 0; i < 4; ++i) {
        ASSERT_EQ(arr1[i], i);
    }
    alloc.deallocate(arr1, 4);
    int* arr3 = alloc.allocate(6);
    alloc.deallocate(arr2, 2);
    alloc.deallocate(arr3, 6);
}

TEST(Test_Allocator, allocation_by_one_object) {
    List<int, Reserve_Allocator<int>> list {1, 1, 2, 4, 5};
    auto itr1 = ++list.begin();
    auto itr2 = std::next(list.begin(), 3);
    list.erase(itr1);
    list.insert(itr2, 3);
    list.push_back(6);
    
    int i = 1;
    ASSERT_EQ(list.size(), 6);
    for (int elem : list) {
        ASSERT_EQ(elem, i++);
    }
}

TEST(Test_Allocator, allocation_for_vector) {
    std::vector<int, Reserve_Allocator<int>> v(4, 0);
    std::vector<int> v2(4, 0);
    v.resize(5, 1);
    v2.resize(5, 1);
    ASSERT_EQ(v.size(), 5);
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(v[i], v2[i]);
    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}