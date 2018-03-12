//
// Created by Michał on 2018-03-05.
//

#include "DoubleBasePalindromes.h"

uint64_t DoubleBasePalindromes(int max_vaule_exculsive) {
    if (max_vaule_exculsive < 1) {
        return 0;
    }
    uint64_t base2[128];
    uint64_t suma = 0;
    uint64_t reversed_number = 0;
    for (uint64_t i = 1; i <= max_vaule_exculsive; i += 2) {
        reversed_number = ReversingNumber(i);
        if (i == reversed_number) {
            uint64_t checking_number = i;
            uint64_t position_multiplier = 0;
            while (checking_number > 0) {
                if (checking_number % 2 == 1) {
                    base2[position_multiplier] = 1;
                }
                else{
                    base2[position_multiplier] = 0;
                }
                checking_number /= 2;
                position_multiplier++;
            }
            std::cout << "\n";
            bool palindrome = true;
            for (int i = 0; i < position_multiplier; ++i) {
                if (!(base2[i] == base2[position_multiplier - i - 1])) {
                    palindrome = false;
                    break;
                }
            }
            if (palindrome == true) {
                suma += i;
            }
        }
    }
    return suma;
};

uint64_t ReversingNumber(uint64_t number) {
    uint64_t checking_number = number;
    uint64_t reversed_number = 0;

    while (checking_number > 0) {
        reversed_number = reversed_number * 10 + checking_number % 10;
        checking_number /= 10;
    }
    return reversed_number;
};