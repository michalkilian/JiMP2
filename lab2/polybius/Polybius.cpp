//
// Created by Michał on 2018-03-12.
//

#include "Polybius.h"

std::string PolybiusCrypt(std::string message){
    char tablica[5][5] = {
            {'A','B','C','D','E'},
            {'F','G','H','I','K'},
            {'L','M','N','O','P'},
            {'Q','R','S','T','U'},
            {'V','W','X','Y','Z'}
    };
    Tabela coordinates;
    std::string output;
    for(int i = 0; i < message.length(); ++i){
        char charToEncrypt = message[i];

        if (charToEncrypt == '\0'){
            return output;
        }
        else{
            coordinates = Encryption(charToEncrypt, tablica);

            if(coordinates.wiersz == 99){
                continue;
            }
            else{
                std::cout << coordinates.wiersz;
                output += coordinates.wiersz;
                output += coordinates.kolumna;
            }
        }
    }

    return output;
}
std::string PolybiusDecrypt(std::string crypted){
    int character;
    int index = 0;
    char* output;
    char tablica[5][5] = {
            {'A','B','C','D','E'},
            {'F','G','H','I','K'},
            {'L','M','N','O','P'},
            {'Q','R','S','T','U'},
            {'V','W','X','Y','Z'}
    };
    for(int i = 0; i<256; ++i){

    }
//    while(znak != EOF) {
//        cout << znak << endl; //wypisz na ekranie
//        char error;
//        error = Decryption(znak, tablica);
//
//        output[index] = error;
//        index++;
//        fscanf(input, "%d ", &znak); //pobierz znak
//    }
//    return output;
}

Tabela Encryption(char charToEncrypt, char array[5][5]){
    Tabela coordinates;
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            if(charToEncrypt == array[i][j]){
                coordinates.wiersz = i+1;
                coordinates.kolumna = j+1;
                return coordinates;
            }
        }
    }
    if (charToEncrypt == 'J'){
        coordinates.kolumna = 4;
        coordinates.wiersz = 2;
    } else{
        coordinates.kolumna = 99;
        coordinates.wiersz = 99;
    }
    return coordinates;
}

char Decryption(int numberToDecrypt, char array[5][5]){
    int a, b;
    b = numberToDecrypt% 10;
    a = (numberToDecrypt-b)/10;
    return array[a-1][b-1];
}