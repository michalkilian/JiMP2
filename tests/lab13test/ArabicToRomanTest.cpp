//
// Created by mwypych on 01.06.17.
//

#include <gtest/gtest.h>
#include <ArabicRoman.h>

TEST(arabic_roman, arabic_to_roman_of_1_is_I) {
    EXPECT_EQ("I", ArabicToRoman(1));
}

TEST(arabic_roman, arabic_to_roman_of_4_is_IV) {
    EXPECT_EQ("IV", ArabicToRoman(4));
}

TEST(arabic_roman, arabic_to_roman_of_8_is_VIII) {
    EXPECT_EQ("VIII", ArabicToRoman(8));
}

TEST(arabic_roman, arabic_to_roman_of_41_is_XLI) {
    EXPECT_EQ("XLI", ArabicToRoman(41));
}

TEST(arabic_roman, arabic_to_roman_of_3999_is_MMMCMXCIX) {
    EXPECT_EQ("MMMCMXCIX", ArabicToRoman(3999));
}

TEST(arabic_roman, arabic_to_roman_of_0_throws_exception) {
    EXPECT_THROW(ArabicToRoman(0), std::invalid_argument);
}

TEST(arabic_roman, arabic_to_roman_of_4000_throws_exception) {
    EXPECT_THROW(ArabicToRoman(4000), std::invalid_argument);
}

