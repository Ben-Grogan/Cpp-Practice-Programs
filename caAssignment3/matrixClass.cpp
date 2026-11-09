#include "matrixClass.h"
//CREATE MATRIX

/**
 * Creates a matrix with the specified number of rows and columns.
 * Dynamically allocates memory for the matrix and initialises
 * every element to zero.
 *
 * @param m The number of rows in the matrix (read-only).
 * @param n The number of columns in the matrix (read-only).
 * @return No return value, as this is a constructor.
 */

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

/**
 * Destroys the matrix and frees its dynamically allocated memory.
 * Deletes the integer array belonging to each row before
 * deleting the array of row pointers.
 *
 * @param None.
 * @return No return value, as this is a destructor.
 */
matrix::~matrix() {
    for (unsigned int i = 0; i < numRows; i++) {
        delete[] data[i];
    }

    delete[] data;
}


// COPY MATRIX

/**
 * Creates a new matrix by copying an existing matrix.
 * Performs a deep copy by allocating separate memory and
 * copying every element from the original matrix.
 * Changes to the new matrix will not affect the original.
 *
 * @param mat The matrix to copy (read-only reference).
 * @return No return value, as this is a constructor.
 */


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

/**
 * Creates a matrix using the elements of an existing 2D array.
 * Dynamically allocates new memory and copies each element
 * from the supplied array into the matrix.
 *
 * @param array Pointer to the 2D integer array containing
 *              the values to copy (read-only in this method).
 * @param m The number of rows in the array (read-only).
 * @param n The number of columns in the array (read-only).
 * @return No return value, as this is a constructor.
 */

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

/**
 * Returns the number of rows in the current matrix.
 * Does not modify any matrix elements or dimensions.
 *
 * @param None.
 * @return An unsigned integer representing the number of rows.
 */
unsigned int matrix::rows() const {
    return numRows;
}

//RETURNS NUMBER OF COLS

/**
 * Returns the number of columns in the current matrix.
 * Does not modify any matrix elements or dimensions.
 *
 * @param None.
 * @return An unsigned integer representing the number of columns.
 */
unsigned int matrix::columns() const {
    return numCols;
}

//RETURN ELEMENT AT i j
/**
 * Retrieves the integer stored at a specified position
 * in the matrix. Does not modify the matrix.
 * Uses zero-based indexing.
 *
 * @param i The row index of the element (read-only).
 * @param j The column index of the element (read-only).
 * @return The integer value stored at position (i, j).
 */
int matrix::get(unsigned i, unsigned j) const{
    return data[i][j];
}


//SET ELEMENT at i j to value

/**
 * Updates an element at a specified position in the matrix.
 * Replaces the existing value with the supplied integer.
 * Modifies the current matrix.
 *
 * @param i The row index of the element to update (read-only).
 * @param j The column index of the element to update (read-only).
 * @param value The new integer to store (read-only).
 * @return No return value (void).
 */
void matrix::set(unsigned i, unsigned j, int value){

    data[i][j] = value;
}

// ADD TWO MATRICES

/**
 * Adds the current matrix to another matrix.
 * Adds corresponding elements and stores the results
 * in a newly allocated matrix.
 * Does not modify either original matrix.
 * Assumes both matrices have matching dimensions.
 *
 * @param mat The matrix to add (read-only reference).
 * @return A new matrix containing the sum of both matrices.
 */

matrix matrix::operator+(const matrix& mat) const {


    // Create a new matrix to store the result
    matrix result(numRows, numCols);

    // Add corresponding elements
    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numCols; j++) {
            result.data[i][j] = data[i][j] + mat.data[i][j];
        }
    }

    // Return the matrix
    return result;
}

// SUBTRACT TWO MATRICES


/**
 * Subtracts another matrix from the current matrix.
 * Subtracts corresponding elements and stores the results
 * in a newly allocated matrix.
 * Does not modify either original matrix.
 * Assumes both matrices have matching dimensions.
 *
 * @param mat The matrix to subtract (read-only reference).
 * @return A new matrix containing the difference between
 *         the current matrix and mat.
 */
matrix matrix::operator-(const matrix& mat) const {

    // Create a new matrix to store the result
    matrix result(numRows, numCols);

    // subtract corresponding elements
    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numCols; j++) {
            result.data[i][j] = data[i][j] - mat.data[i][j];
        }
    }

    // Return the matrix
    return result;
}

// MULTIPLY TWO MATRICES

/**
 * Multiplies the current matrix by another matrix using
 * standard matrix multiplication.
 * Each result element is calculated by multiplying the
 * corresponding row and column elements and summing them.
 * Does not modify either original matrix.
 * Assumes the number of columns in the current matrix
 * equals the number of rows in mat.
 *
 * @param mat The matrix to multiply by (read-only reference).
 * @return A new matrix containing the multiplication result.
 */
matrix matrix::operator*(const matrix& mat) const {

    // Create a matrix with rows from A and columns from B
    matrix result(numRows, mat.numCols);

    // Loop through rows of the first matrix
    for (unsigned int i = 0; i < numRows; i++) {

        // Loop through columns of the second matrix
        for (unsigned int j = 0; j < mat.numCols; j++) {

            // Multiply and sum corresponding elements
            for (unsigned int k = 0; k < numCols; k++) {
                result.data[i][j] += data[i][k] * mat.data[k][j];
            }
        }
    }

    return result;
}

// TRANSPOSE MATRIX

/**
 * Calculates the transpose of the current matrix.
 * Swaps the rows and columns so that the element at
 * position (i, j) moves to position (j, i).
 * Does not modify the original matrix.
 *
 * @param None.
 * @return A new matrix containing the transpose of
 *         the current matrix.
 */
matrix matrix::operator~() const {

    // Create a new matrix with swapped dimensions
    matrix result(numCols, numRows);

    // Swap the rows and columns
    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numCols; j++) {
            result.data[j][i] = data[i][j];
        }
    }

    // Return the transposed matrix
    return result;
}

// CHECK IF TWO MATRICES ARE EQUAL

/**
 * Checks whether the current matrix and another matrix
 * are equal. Two matrices are equal if they have identical
 * dimensions and the same integer at every corresponding
 * position. Does not modify either matrix.
 *
 * @param mat The matrix to compare (read-only reference).
 * @return true if both matrices are equal, otherwise false.
 */
bool matrix::operator==(const matrix& mat) const {

    // Check if dimensions are the same
    if (numRows != mat.numRows || numCols != mat.numCols) {
        return false;
    }

    // Compare every element
    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numCols; j++) {

            // If any elements differ, matrices are not equal
            if (data[i][j] != mat.data[i][j]) {
                return false;
            }
        }
    }

    // All elements matched
    return true;
}

// RETURN STRING REPRESENTATION OF MATRIX

/**
 * Converts the current matrix into a string representation.
 * Includes every element, with spaces separating columns
 * and newline characters separating rows.
 * Does not modify the matrix.
 *
 * @param None.
 * @return A string containing all elements of the matrix.
 */
string matrix::toStr() const {

    string result = "";

    // Loop through every row
    for (unsigned int i = 0; i < numRows; i++) {

        // Loop through every column
        for (unsigned int j = 0; j < numCols; j++) {

            // Convert the integer to a string
            result += to_string(data[i][j]);

            // Add a space between elements
            if (j < numCols - 1) {
                result += " ";
            }
        }

        // Move to the next row
        if (i < numRows - 1) {
            result += "\n";
        }
    }

    return result;
}
