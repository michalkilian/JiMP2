//
// Created by Michał on 2018-03-05.
//

#include "DoubleBasePalindromes.h"
#include <iostream>

int main() {
    int max_vaule_exculsive = 1;
    std::cin >> max_vaule_exculsive;
    std::cout << "wynik: " << DoubleBasePalindromes(max_vaule_exculsive);
}