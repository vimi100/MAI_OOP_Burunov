#include <gtest/gtest.h>
#include "four.h"

TEST(test1, basic_test_set) {
    bool check1 = true;
    try{
        Four not_11dec1 (0, 'A');
    }
    catch(exception &ex){
        check1 = false;
    }

    ASSERT_FALSE(check1);
}

TEST(test2, basic_test_set) {
    bool check2 = true;
    try{
        Four not_11dec2 (5, 'B');
    }
    catch(exception &ex){
        check2 = false;
    }

    ASSERT_FALSE(check2);
}

TEST(test3, basic_test_set) {
    bool check3 = true;
    try{
        Four not_11dec3 {'B', 'A', 'A', 'a', '8'};
    }
    catch(exception &ex){
        check3 = false;
    }

    ASSERT_FALSE(check3);
}

TEST(test4, basic_test_set) {
    bool check4 = true;
    try{
        Four not_11dec4 {""};
    }
    catch(exception &ex){
        check4 = false;
    }

    ASSERT_FALSE(check4);
}

TEST(test5, basic_test_set) {
    bool check5 = true;
    try{
        Four not_11dec5 {"aaab4"};
    }
    catch(exception &ex){
        check5 = false;
    }

    ASSERT_FALSE(check5);
}

TEST(test6, basic_test_set) {
    bool check6 = true;
    try{
        Four not_11dec6_part {"bbcbaga"};
        Four not_11dec6(not_11dec6_part);
    }
    catch(exception &ex){
        check6 = false;
    }

    ASSERT_FALSE(check6);
}

TEST(test7, basic_test_set) {
    bool check7 = true;
    try{
        Four not_11dec7_part {""};
        Four not_11dec7(not_11dec7_part);
    }
    catch(exception &ex){
        check7 = false;
    }

    ASSERT_FALSE(check7);
}

TEST(test8, basic_test_set) {
    bool check8 = true;
    try{
        Four not_11dec8_part {""};
        Four not_11dec8(move(not_11dec8_part));
    }
    catch(exception &ex){
        check8 = false;
    }

    ASSERT_FALSE(check8);
}

TEST(test9, basic_test_set) {
    bool check9 = true;
    try{
        Four not_11dec9_part {"vbwigiuuwhvu"};
        Four not_11dec9(move(not_11dec9_part));
    }
    catch(exception &ex){
        check9 = false;
    }

    ASSERT_FALSE(check9);
}

TEST(test10, basic_test_set) {
    Four left1("AAAA9");
    Four right1("AAA78");
    Four result1(left1.addition(right1));
    Four expected1("1aaa76");
    ASSERT_TRUE(expected1.equal(result1));
}

TEST(test11, basic_test_set) {
    Four left2("AAAA9");
    Four right2("AAA78");
    Four result2(left2.subtraction(right2));
    Four expected2("31");
    ASSERT_TRUE(expected2.equal(result2));
}

TEST(test12, basic_test_set) {
    bool check10 = true;
    Four left3("AA");
    Four right3("AAA78");
    try {
        left3.subtraction(right3);
    }
    catch (exception &ex) {
        check10 = false;
    }
    ASSERT_FALSE(check10);
}

TEST(test13, basic_test_set) {
    bool check11 = false;
    Four left4("AAAA9");
    Four right4("aaaa9");
    check11 = left4.equal(right4);
    ASSERT_TRUE(check11);
}

TEST(test14, basic_test_set) {
    bool check12 = false;
    Four left5("AAAA9818");
    Four right5("AAAA9817");
    check12 = left5.bigger(right5);
    ASSERT_TRUE(check12);
}

TEST(test15, basic_test_set) {
    bool check13 = false;
    Four left6("AAAA9818");
    Four right6("AAAA9819");
    check13 = left6.bigger(right6);
    ASSERT_FALSE(check13);
}

TEST(test16, basic_test_set) {
    bool check14 = false;
    Four left7("AAAA9819");
    Four right7("AAAA9819");
    check14 = left7.bigger(right7);
    ASSERT_FALSE(check14);
}

TEST(test17, basic_test_set) {
    bool check15 = false;
    Four left8("AAAA9818");
    Four right8("AAAA9819");
    check15 = left8.smaller(right8);
    ASSERT_TRUE(check15);
}

TEST(test18, basic_test_set) {
    bool check16 = false;
    Four left9("AAAA981A");
    Four right9("AAAA9819");
    check16 = left9.smaller(right9);
    ASSERT_FALSE(check16);
}

TEST(test19, basic_test_set) {
    bool check17 = false;
    Four left10("AAAA981A");
    Four right10("AAAA981A");
    check17 = left10.smaller(right10);
    ASSERT_FALSE(check17);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}