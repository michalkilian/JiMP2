//
// Created by Michał on 2018-03-05.
//

#include "DoubleBasePalindromes.h"

uint64_t DoubleBasePalindromes(int max_vaule_exculsive) {
    uint64_t suma = 0;
    uint64_t reversed_number = 0;
    uint64_t base_2_number = 0;
    for (uint64_t i = 1; i <= max_vaule_exculsive; i += 2) {
        reversed_number = ReversingNumber(i);
        base_2_number = 0;
        if (i == reversed_number){
            uint64_t checking_number = i;
            uint64_t position_multiplier = 1;
            while (checking_number > 0){
                if (checking_number % 2 == 1){
                    base_2_number += position_multiplier;
                }
                checking_number /= 2;
                position_multiplier *= 10;
            }
            reversed_number = ReversingNumber(base_2_number);
            if (reversed_number == base_2_number){
                suma += i;
            }
        }
    }
    return suma;
};

uint64_t ReversingNumber(uint64_t number){
    uint64_t checking_number = number;
    uint64_t reversed_number = 0;

    while (checking_number > 0){
        reversed_number = reversed_number*10 + checking_number%10;
        checking_number /= 10;
    }
    return reversed_number;
};