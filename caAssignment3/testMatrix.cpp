#include <iostream>
#include "matrixClass.h"

using namespace std;


// Test case 1 for matrix(unsigned int m, unsigned int n)
// Checks that the matrix is created with the correct dimensions
// and all elements are initialised to 0.
void Test_Case_1_Constructor() {
    matrix A(2, 3);

    bool passed = true;

    if (A.rows() != 2 || A.columns() != 3) {
        passed = false;
    }

    for (unsigned int i = 0; i < 2; i++) {
        for (unsigned int j = 0; j < 3; j++) {
            if (A.get(i, j) != 0) {
                passed = false;
            }
        }
    }

    cout << "Constructor Test: "
         << (passed ? "PASS" : "FAIL") << endl;
}


// Test case 1 for matrix(const matrix& mat)
// Checks that all elements are copied correctly
// and the copied matrix has its own memory.
void Test_Case_1_CopyConstructor() {
    matrix A(2, 2);

    A.set(0, 0, 5);
    A.set(0, 1, 10);
    A.set(1, 0, 15);
    A.set(1, 1, 20);

    matrix B(A);

    bool passed = true;

    for (unsigned int i = 0; i < 2; i++) {
        for (unsigned int j = 0; j < 2; j++) {
            if (A.get(i, j) != B.get(i, j)) {
                passed = false;
            }
        }
    }

    // Check that changing B doesn't affect A
    B.set(0, 0, 100);

    if (A.get(0, 0) != 5 || B.get(0, 0) != 100) {
        passed = false;
    }

    cout << "Copy Constructor Test: "
         << (passed ? "PASS" : "FAIL") << endl;
}


// Test case 1 for matrix(int** array, unsigned int m, unsigned int n)
// Checks that a matrix is correctly initialised from a 2D array.
void Test_Case_1_ArrayConstructor() {
    int row1[] = {1, 2, 3};
    int row2[] = {4, 5, 6};

    int* array[] = {row1, row2};

    matrix A(array, 2, 3);

    bool passed = true;

    for (unsigned int i = 0; i < 2; i++) {
        for (unsigned int j = 0; j < 3; j++) {
            if (A.get(i, j) != array[i][j]) {
                passed = false;
            }
        }
    }

    // Check that the matrix has its own copy of the data
    array[0][0] = 100;

    if (A.get(0, 0) != 1) {
        passed = false;
    }

    cout << "Array Constructor Test: "
         << (passed ? "PASS" : "FAIL") << endl;
}


// Test case 1 for rows()
// Checks that the correct number of rows is returned.
void Test_Case_1_Rows() {
    matrix A(3, 4);

    cout << "Rows Test: "
         << (A.rows() == 3 ? "PASS" : "FAIL") << endl;
}


// Test case 1 for columns()
// Checks that the correct number of columns is returned.
void Test_Case_1_Columns() {
    matrix A(3, 4);

    cout << "Columns Test: "
         << (A.columns() == 4 ? "PASS" : "FAIL") << endl;
}


// Test case 1 for get()
// Checks that get() returns the correct element.
void Test_Case_1_Get() {
    matrix A(2, 3);

    A.set(0, 0, 5);
    A.set(1, 2, 10);

    bool passed = (A.get(0, 0) == 5 &&
                   A.get(1, 2) == 10);

    cout << "Get Test: "
         << (passed ? "PASS" : "FAIL") << endl;
}


// Test case 1 for set()
// Checks that set() correctly changes matrix elements.
void Test_Case_1_Set() {
    matrix A(2, 3);

    A.set(0, 0, 15);
    A.set(1, 2, 25);

    bool passed = (A.get(0, 0) == 15 &&
                   A.get(1, 2) == 25);

    cout << "Set Test: "
         << (passed ? "PASS" : "FAIL") << endl;
}


// Test case 1 for ~matrix()
// Basic check that dynamically allocated matrices
// can be destroyed without an obvious runtime error.
// This does not prove that memory management is leak-free.
void Test_Case_1_Destructor() {
    matrix* A = new matrix(3, 3);

    A->set(0, 0, 10);

    delete A;

    cout << "Destructor Test: PASS (basic check)" << endl;
}


// Run all test cases
int main() {
    cout << "===== MATRIX TEST CASES =====" << endl;

    Test_Case_1_Constructor();
    Test_Case_1_CopyConstructor();
    Test_Case_1_ArrayConstructor();
    Test_Case_1_Rows();
    Test_Case_1_Columns();
    Test_Case_1_Get();
    Test_Case_1_Set();
    Test_Case_1_Destructor();

    return 0;
}