//
// Created by Michał on 2018-03-19.
//

#include "XorCypherBreaker.h"

std::string ChangeKey(std::string key, int counter) {
    key[0] = 'a' + counter / (26 * 26);
    key[1] = 'a' + counter / 26 % 26;
    key[2] = 'a' + counter % 26;
    return key;
}

int BackXOR(int letter, std::string key, int counter) {
    return (key[counter - 1] ^ letter);
}

std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<std::string> &dictionary) {
    std::string key;
    for (int i = 0; i < key_length; i++) {
        key += "a";
    }
    int max = 0;
    std::string key_max;
    int j = 0;
    int counter = 0;
    while (true) {
        counter = 0;
        for (int i = 0; i < cryptogram.size() - 5; i++) {
            std::string checking;
            checking += (BackXOR(cryptogram[i], key, 1));
            checking += (BackXOR(cryptogram[i + 1], key, 2));
            checking += (BackXOR(cryptogram[i + 2], key, 3));
            checking += (BackXOR(cryptogram[i + 3], key, 1));


            if (find(dictionary.begin(), dictionary.end(), checking) != dictionary.end()) {
                counter++;
            }
            checking = (BackXOR(cryptogram[i], key, 1));
            checking += (BackXOR(cryptogram[i + 1], key, 1));

            if (find(dictionary.begin(), dictionary.end(), checking) != dictionary.end()) {
                counter++;
            }

            checking = (BackXOR(cryptogram[i], key, 1));
            checking += (BackXOR(cryptogram[i + 1], key, 1));
            checking += (BackXOR(cryptogram[i + 2], key, 1));

            if (find(dictionary.begin(), dictionary.end(), checking) != dictionary.end()) {
                counter++;
            }

            if (counter > max) {
                max = counter;
                key_max = key;
            }

        }
        key = ChangeKey(key, j);
        j++;
        if (key == "zzz") {
            return key_max;
        }
    }

}