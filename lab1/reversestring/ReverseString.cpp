//
// Created by mwypych on 02.02.17.
//
#include "ReverseString.h"

int factorial(int value) {
  int facValue = 1;
  if(value >= 13 || value <= -13) {
    facValue = 0;
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
