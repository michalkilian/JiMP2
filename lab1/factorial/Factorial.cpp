//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int Factorial(int value) {
  int facValue = 1;
  if(CheckOutOfRange(value)) {
    return 0;
  }
  else if(value > 0) {
    for (int i = 2; i <= value; ++i) {
      facValue *= i;
    }
  }
  else {
    for(int i = -1; i >= value; --i) {
      facValue *= i;
    }
  }

  return facValue;
}

bool CheckOutOfRange(int value) { return value >= 13 || value <= -13; }
