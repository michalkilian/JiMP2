//
// Created by Michał on 2018-03-12.
//
#include <iostream>
#include <fstream>
#include "Polybius.h"

using namespace std;


int main(int argc, char* argv[ ]) {
    ifstream input(argv[1]);
    ofstream output (argv[2], ios_base::in | ios_base::app);
    if(argc != 4){
        cout << "Wrong number of arguments\n";
        return 0;
    }
    char polybiusMode = argv[3][0];
    if(polybiusMode == '1') {
        char line[256];
        while(!input.eof()) {
            input.getline(line,256);
            output << PolybiusCrypt(line) << "\n";
        }
        input.close();
        output.close();
    } else {
        char line[256];
        while(!input.eof()){
            input.getline(line,256);
            output << PolybiusDecrypt(line);
        }
    }
}