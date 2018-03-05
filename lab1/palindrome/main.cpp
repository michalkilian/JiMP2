//
// Created by Michał on 2018-03-04.
//

#include <iostream>
#include "Palindrome.h"

int main() {
    int n = 0;
    std::cout << "1. Sprawdz czy wyraz jest palindromem\n" << "2. Wyjscie\n";
    while (!(n == 1 || n == 2)) {
        std::cin >> n;
    }
    if (n == 1) {
        std::cout << "Podaj wyraz do sprawdzenia: ";
        std::string str;
        std::cin >> str;
        if (is_palindrome(str)) {
            std::cout << "tak";
        } else {
            std::cout << "nie";
        }
    }

    return 0;
}
