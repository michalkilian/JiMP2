//
// Created by kilimich on 18.04.18.
//

#include "Kula.h"
#include "Kolo.h"
#include <iostream>

using namespace std;

int main(){
    Kula k(0,0,0,10);
    Kolo o(0,0,10);
    cout << k.Pole() << endl;
    cout << k.Pole()/4 << endl;
    cout << o.Pole();
    Kolo *kk = &k;
    cout << endl << kk->Pole();
}