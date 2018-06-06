//
// Created by mwypych on 01.06.17.
//

//
// Created by mwypych on 01.06.17.
//

#include <gtest/gtest.h>
#include <ArabicRoman.h>

TEST(arabic_roman, roman_to_arabic_of_I_is_1) {
    EXPECT_EQ(1, RomanToArabic("I"));
}

TEST(arabic_roman, roman_to_arabic_of_IV_is_4) {
    EXPECT_EQ(4, RomanToArabic("IV"));
}

TEST(arabic_roman, roman_to_arabic_of_VIII_is_8) {
    EXPECT_EQ(8, RomanToArabic("VIII"));
}

TEST(arabic_roman, roman_to_arabic_of_XLI_is_41) {
    EXPECT_EQ(41, RomanToArabic("XLI"));
}

TEST(arabic_roman, roman_to_arabic_more_than_1_L_D_V_next_to_each_other_throw_exception) {
    EXPECT_THROW(RomanToArabic("LL"), std::invalid_argument);
    EXPECT_THROW(RomanToArabic("DD"), std::invalid_argument);
    EXPECT_THROW(RomanToArabic("VV"), std::invalid_argument);
}

TEST(arabic_roman, roman_to_arabic_more_than_3_I_X_C_M_next_to_each_other_throw_exception) {
    EXPECT_THROW(RomanToArabic("XXXX"), std::invalid_argument);
    EXPECT_THROW(RomanToArabic("IIXIIII"), std::invalid_argument);
    EXPECT_THROW(RomanToArabic("CCCC"), std::invalid_argument);
    EXPECT_THROW(RomanToArabic("MMMMM"), std::invalid_argument);
}
TEST(arabic_roman, roman_to_arabic_wrong_order_of_characters_throw_exception) {
    EXPECT_THROW(RomanToArabic("LD"), std::invalid_argument);
    EXPECT_THROW(RomanToArabic("IIMMMXC"), std::invalid_argument);
    EXPECT_THROW(RomanToArabic("XLIL"), std::invalid_argument);
}
TEST(arabic_roman, roman_to_arabic_invalid_characters){
    EXPECT_THROW(RomanToArabic("JXXII"), std::invalid_argument);
}
