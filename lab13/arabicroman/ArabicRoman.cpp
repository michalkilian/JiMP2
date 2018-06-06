//
// Created by kilimich on 06.06.18.
//

#include "ArabicRoman.h"
#include <vector>

std::string ArabicToRoman(int liczba){
    if (liczba <= 0 || liczba > 3999){
        throw std::invalid_argument("Invalid argument");
    }

    const int numbers[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    const std::string chars[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

    std::string result = "";

    for(int i = 12; i >= 0; --i){
        while (liczba >= numbers[i]){
            liczba -= numbers[i];
            result += chars[i];
        }
    }
    return result;
}

int value(char roman) {
    switch(roman) {
        case 'I':return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D':return 500;
        case 'M':return 1000;
    }
}

int RomanToArabic(std::string input){

    std::regex non_roman("[^IVXLCDM]");
    if (std::regex_search(input, non_roman)== true){
        throw std::invalid_argument("Invalid argument");
    }
    std::vector<std::regex> regexes;
    regexes.push_back(std::regex ("X{4}"));
    regexes.push_back(std::regex ("I{4}"));
    regexes.push_back(std::regex ("M{4}"));
    regexes.push_back(std::regex ("C{4}"));
    regexes.push_back(std::regex ("L{2}"));
    regexes.push_back(std::regex ("D{2}"));
    regexes.push_back(std::regex ("V{2}"));
    regexes.push_back(std::regex ("I+[MDCL]"));
    regexes.push_back(std::regex ("II+[XV]"));
    regexes.push_back(std::regex ("V[^I]"));
    regexes.push_back(std::regex ("X[^IVCL]"));
    regexes.push_back(std::regex ("L[^IVX]"));
    regexes.push_back(std::regex ("LD"));

    for (auto p:regexes) {
        if (std::regex_search(input, p) == true) {
            throw std::invalid_argument("Invalid argument");
        }
    }

    int sum=0; char prev='%';
    for(int i=(input.length()-1); i>=0; i--) {
        if(value(input[i])<sum && (input[i]!=prev)) {
            sum -= value(input[i]);
            prev = input[i];
        } else {
            sum += value(input[i]);
            prev = input[i];
        }
    }
    return sum;
}