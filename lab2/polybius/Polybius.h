//
// Created by Michał on 2018-03-12.
//

#ifndef JIMP_EXERCISES_POLYBIUS_H
#define JIMP_EXERCISES_POLYBIUS_H

#include <string>
#include <iostream>

typedef struct {
    char wiersz, kolumna;
} Tabela;

std::string PolybiusCrypt(std::string message);
std::string PolybiusDecrypt(std::string crypted);
Tabela Encryption(char charToEncrypt, char array[5][5]);
char Decryption(int numberToDecrypt, char array[5][5]);

#endif //JIMP_EXERCISES_POLYBIUS_H
