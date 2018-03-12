//
// Created by Michał on 2018-03-12.
//

#include "Polybius.h"

std::map<char, unsigned int> Crypting = {
        {'A', 11},
        {'B', 12},
        {'C', 13},
        {'D', 14},
        {'E', 15},
        {'F', 21},
        {'G', 22},
        {'H', 23},
        {'I', 24},
        {'J', 24},
        {'K', 25},
        {'L', 31},
        {'M', 32},
        {'N', 33},
        {'O', 34},
        {'P', 35},
        {'Q', 41},
        {'R', 42},
        {'S', 43},
        {'T', 44},
        {'U', 45},
        {'V', 51},
        {'W', 52},
        {'X', 53},
        {'Y', 54},
        {'Z', 55},
};

std::map<unsigned int, char> Decrypt = {
        {11, 'a'},
        {12, 'b'},
        {13, 'c'},
        {14, 'd'},
        {15, 'e'},
        {21, 'f'},
        {22, 'g'},
        {23, 'h'},
        {24, 'i'},
        {24, 'j'},
        {25, 'k'},
        {31, 'l'},
        {32, 'm'},
        {33, 'n'},
        {34, 'o'},
        {35, 'p'},
        {41, 'q'},
        {42, 'r'},
        {43, 's'},
        {44, 't'},
        {45, 'u'},
        {51, 'v'},
        {52, 'w'},
        {53, 'x'},
        {54, 'y'},
        {55, 'z'},
};

std::string TextPreparation(std::string message) {
    message.erase(remove_if(message.begin(), message.end(), [](char c) { return !isalpha(c); }), message.end());
    std::string readyText;
    for (int i = 0; i < message.length(); i++) {
        readyText += toupper(message[i]);
    }
    return readyText;
}
std::string PolybiusCrypt(std::string message){
    std::string preparedText = TextPreparation(message);
    std::string polybiusEncrypted;
    int intChar;
    for (int i = 0; i < preparedText.length(); i++) {
        intChar = Crypting[preparedText[i]];
        polybiusEncrypted += std::to_string(intChar);
    }
    return polybiusEncrypted;
}

std::string PolybiusDecrypt(std::string crypted){
    std::string polybiusDecrypted;
    for (int i = 0; i < crypted.length(); i = i + 2) {
        std::string twoInts;
        if (crypted.length() >= 2) {
            twoInts += crypted[i];
            twoInts += crypted[i + 1];
        }
        int intToCheck = stoi(twoInts, nullptr, 10);
        polybiusDecrypted += Decrypt[intToCheck];
    }
    return polybiusDecrypted;
}