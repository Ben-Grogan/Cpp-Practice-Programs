#include "matrixClass.h"

//CREATE MATRIX

matrix::matrix(unsigned int m, unsigned int n){
    numRows = m;
    numCols = n;

    //dynamic memory allocation for rows
    data = new int*[numRows];

    //dymamic memory allocation for cols, in each row
    for(unsigned int i=0; i < numRows; i++){
        data[i] = new int [numCols]();
    }

    //initializing, filling with 0
   for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numCols; j++) {
            data[i][j] = 0;
        }
    }    

}

// FREEING MEMORY
matrix::~matrix() {
    for (unsigned int i = 0; i < numRows; i++) {
        delete[] data[i];
    }

    delete[] data;
}


// COPY MATRIX

matrix::matrix(const matrix &mat){
    numRows = mat.numRows;
    numCols = mat.numCols;

    //dynamic memory allocation for rows
    data = new int*[numRows];

    //dymamic memory allocation for cols, in each row
    for(unsigned int i=0; i < numRows; i++){
        data[i] = new int [numCols]();
    }

    //initializing, filling with 0
   for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numCols; j++) {
            data[i][j] = mat.data[i][j];
        }
    }   
}

//INITIALISE MATRIX AS 2D ARRAY
matrix::matrix(int** array , unsigned int m , unsigned int n ){
    numRows = m;
    numCols = n;

    // Allocate memory for the rows
    data = new int*[numRows];

    // Allocate memory for each row and copy the values
    for (unsigned int i = 0; i < numRows; i++) {
        data[i] = new int[numCols];

        for (unsigned int j = 0; j < numCols; j++) {
            data[i][j] = array[i][j];
        }
    }
}


//RETURNS NUMBER OF ROWS
unsigned int matrix::rows() const {
    return numRows;
}

//RETURNS NUMBER OF COLS
unsigned int matrix::columns() const {
    return numCols;
}

//RETURN ELEMENT AT i j
int matrix::get(unsigned i, unsigned j) const{
    return data[i][j];
}


//SET ELEMENT at i j to value
void matrix::set(unsigned i, unsigned j, int value){

    data[i][j] = value;
}
