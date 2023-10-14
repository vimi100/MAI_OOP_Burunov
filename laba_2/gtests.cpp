#include <gtest/gtest.h>
#include "four.h"

TEST(test1, basic_test_set) {
    bool check1 = true;
    try{
        Four not_4dec1 (0, '1');
    }
    catch(exception &ex){
        check1 = false;
    }

    ASSERT_FALSE(check1);
}

TEST(test2, basic_test_set) {
    bool check2 = true;
    try{
        Four not_4dec2 (5, 'J');
    }
    catch(exception &ex){
        check2 = false;
    }

    ASSERT_FALSE(check2);
}

TEST(test3, basic_test_set) {
    bool check3 = true;
    try{
        Four not_4dec3 {'0', '1', '2', '3', '8'};
    }
    catch(exception &ex){
        check3 = false;
    }

    ASSERT_FALSE(check3);
}

TEST(test4, basic_test_set) {
    bool check4 = true;
    try{
        Four not_4dec4 {""};
    }
    catch(exception &ex){
        check4 = false;
    }

    ASSERT_FALSE(check4);
}

TEST(test5, basic_test_set) {
    bool check5 = true;
    try{
        Four not_4dec5 {"1222334"};
    }
    catch(exception &ex){
        check5 = false;
    }

    ASSERT_FALSE(check5);
}

TEST(test6, basic_test_set) {
    bool check6 = true;
    try{
        Four not_4dec6_part {"444421"};
        Four not_4dec6(not_4dec6_part);
    }
    catch(exception &ex){
        check6 = false;
    }

    ASSERT_FALSE(check6);
}

TEST(test7, basic_test_set) {
    bool check7 = true;
    try{
        Four not_4dec7_part {""};
        Four not_4dec7(not_4dec7_part);
    }
    catch(exception &ex){
        check7 = false;
    }

    ASSERT_FALSE(check7);
}

TEST(test8, basic_test_set) {
    bool check8 = true;
    try{
        Four not_4dec8_part {""};
        Four not_4dec8(move(not_4dec8_part));
    }
    catch(exception &ex){
        check8 = false;
    }

    ASSERT_FALSE(check8);
}

TEST(test9, basic_test_set) {
    bool check9 = true;
    try{
        Four not_4dec9_part {"dhvu"};
        Four not_4dec9(move(not_4dec9_part));
    }
    catch(exception &ex){
        check9 = false;
    }

    ASSERT_FALSE(check9);
}

TEST(test10, basic_test_set) {
    Four left1("3333");
    Four right1("1");
    Four result1(left1.addition(right1));
    Four expected1("10000");
    ASSERT_TRUE(expected1.equal(result1));
}

TEST(test11, basic_test_set) {
    Four left2("12333");
    Four right2("1223");
    Four result2(left2.subtraction(right2));
    Four expected2("11110");
    ASSERT_TRUE(expected2.equal(result2));
}

TEST(test12, basic_test_set) {
    bool check10 = true;
    Four left3("1");
    Four right3("333");
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
    Four left4{'1', '2', '3'};
    Four right4("123");
    check11 = left4.equal(right4);
    ASSERT_TRUE(check11);
}

TEST(test14, basic_test_set) {
    bool check12 = false;
    Four left5("123331");
    Four right5("123330");
    check12 = left5.bigger(right5);
    ASSERT_TRUE(check12);
}

TEST(test15, basic_test_set) {
    bool check13 = false;
    Four left6("2");
    Four right6("201");
    check13 = left6.bigger(right6);
    ASSERT_FALSE(check13);
}

TEST(test16, basic_test_set) {
    bool check14 = false;
    Four left7("10202");
    Four right7("10202");
    check14 = left7.bigger(right7);
    ASSERT_FALSE(check14);
}

TEST(test17, basic_test_set) {
    bool check15 = false;
    Four left8("333");
    Four right8("1000");
    check15 = left8.smaller(right8);
    ASSERT_TRUE(check15);
}

TEST(test18, basic_test_set) {
    bool check16 = false;
    Four left9("111113");
    Four right9("111112");
    check16 = left9.smaller(right9);
    ASSERT_FALSE(check16);
}

TEST(test19, basic_test_set) {
    bool check17 = false;
    Four left10("2232");
    Four right10("2232");
    check17 = left10.smaller(right10);
    ASSERT_FALSE(check17);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}