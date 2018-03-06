//
// Created by kilimich on 06.03.18.
//

#include "Array2D.h"
#include <iostream>


int **Array2D(int n_rows, int n_columns){

    if(CheckIfPossitive(n_rows, n_columns)){
        return nullptr;
    }
    int **array = NewArray2D(n_rows, n_columns);

    FillArray2D(n_rows, n_columns, array);

    return array;
}

void FillArray2D(int n_rows, int n_columns, int *const *array) {
    int counter = 1;
    for(int i = 0; i < n_rows; ++i){
        for(int j = 0; j < n_columns; ++j){
            array[i][j] = counter;
            counter++;
        }
    }
}

int **NewArray2D(int n_rows, int n_columns) {
    int** array = new int*[n_rows];
    for(int i = 0; i < n_rows; ++i)
        array[i] = new int[n_columns];
    return array;
}

bool CheckIfPossitive(int n_rows, int n_columns) { return n_rows <= 0 || n_columns <= 0; }

void DeleteArray2D(int **array, int n_rows, int n_columns){
    for(int i = 0; i < n_rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

}