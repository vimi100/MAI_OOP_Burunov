#include <gtest/gtest.h>
#include "vowel.h"

TEST(test_01, basic_test_set) {
    ASSERT_EQ(countVowels(""), 0);
}

TEST(test_02, basic_test_set) {
    ASSERT_EQ(countVowels("   "), 0);
}

TEST(test_03, basic_test_set) {
    ASSERT_EQ(countVowels("im so happy cause today i found my friends"), 16);
}

TEST(test_04_basic_test_set_Test, basic_test_set) {
    ASSERT_EQ(countVowels("0"), 0);
}

TEST(test_05, basic_test_set) {
    ASSERT_EQ(countVowels("in there may be your adds"), 10);
}

TEST(test_06, basic_test_set) {
    ASSERT_EQ(countVowels("blablabalaeueeeeo"), 11);
}

TEST(test_07, basic_test_set) {
    ASSERT_EQ(countVowels("i wish i could eat your cancer when you turn black"), 18);
}

TEST(test_08, basic_test_set) {
    ASSERT_EQ(countVowels("qwrqwrhqwurhqwerh"), 2);
}

int main (int args, char **argv) {
    testing::InitGoogleTest(&args, argv);
    return RUN_ALL_TESTS();
}