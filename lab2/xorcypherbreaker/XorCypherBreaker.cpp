//
// Created by Michał on 2018-03-19.
//

#include "XorCypherBreaker.h"

std::string
XorCypherBreaker(const std::vector<char> &cryptogram, int key_length, const std::vector<std::string> &dictionary) {
    char currentChar;
    std::string decryptedWord;
    std::string key;

    for (char i = 'a'; i <= 'z'; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            for (char k = 'a'; k <= 'z'; k++) {
                int wordsFoundInDic = 0;
                int numberOfWords = 0;
                int currentIndex = 0;
                key = "";
                key += i;
                key += j;
                key += k;

                for (char encryptedC: cryptogram) {
                    currentChar = encryptedC ^ key.at(currentIndex % 3);
                    currentIndex++;
                    if (currentChar >= 'a' && currentChar <= 'z') {
                        decryptedWord += currentChar;
                        continue;
                    } else if (decryptedWord.size() != 0) {
                        if (std::find(dictionary.begin(), dictionary.end(), decryptedWord) != dictionary.end()) {
                            wordsFoundInDic++;
                        }
                        numberOfWords++;
                        if (numberOfWords > 20 && wordsFoundInDic * 100 / numberOfWords > 35) {
                            return key;
                        }
                        decryptedWord = "";
                    }
                }
            }
        }
    }
    return key;
}