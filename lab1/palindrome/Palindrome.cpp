//
// Created by Michał on 2018-03-05.
//

#include "Palindrome.h"

bool is_palindrome(std::string str) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != str[str.length() - i - 1]) {
            return false;
        }
    }
    return true;
}