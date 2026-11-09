
#include <iostream>
#include <string>
#include "matrixClass.h"

using namespace std;


// Test case 1 for matrix(unsigned int m, unsigned int n).
// Checks that a matrix is created with the correct dimensions
// and every element is initialised to zero.
void Test_Case_1_Constructor() {
    matrix A(2, 3);

    bool passed = (A.rows() == 2 && A.columns() == 3);

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


// Test case 1 for matrix(const matrix& mat).
// Checks that the copy constructor copies all elements
// and that the two matrices use independent memory.
void Test_Case_1_CopyConstructor() {
    matrix A(2, 2);

    A.set(0, 0, 5);
    A.set(0, 1, 10);
    A.set(1, 0, 15);
    A.set(1, 1, 20);

    matrix B(A);

    bool passed = (B.rows() == 2 && B.columns() == 2);

    for (unsigned int i = 0; i < 2; i++) {
        for (unsigned int j = 0; j < 2; j++) {
            if (A.get(i, j) != B.get(i, j)) {
                passed = false;
            }
        }
    }

    // Changing B should not change A.
    B.set(0, 0, 100);

    if (A.get(0, 0) != 5 || B.get(0, 0) != 100) {
        passed = false;
    }

    cout << "Copy Constructor Test: "
         << (passed ? "PASS" : "FAIL") << endl;
}


// Test case 1 for matrix(int** array, unsigned int m, unsigned int n).
// Checks that values are copied correctly from a 2D array.
void Test_Case_1_ArrayConstructor() {
    int row1[] = {1, 2, 3};
    int row2[] = {4, 5, 6};

    int* array[] = {row1, row2};

    matrix A(array, 2, 3);

    bool passed = (A.rows() == 2 && A.columns() == 3);

    for (unsigned int i = 0; i < 2; i++) {
        for (unsigned int j = 0; j < 3; j++) {
            if (A.get(i, j) != array[i][j]) {
                passed = false;
            }
        }
    }

    // Check that A has its own copy of the data.
    array[0][0] = 100;

    if (A.get(0, 0) != 1) {
        passed = false;
    }

    cout << "Array Constructor Test: "
         << (passed ? "PASS" : "FAIL") << endl;
}


// Test case 1 for rows().
// Checks that the correct number of rows is returned.
void Test_Case_1_Rows() {
    matrix A(3, 4);

    bool passed = (A.rows() == 3);

    cout << "Rows Test: "
         << (passed ? "PASS" : "FAIL") << endl;
}


// Test case 1 for columns().
// Checks that the correct number of columns is returned.
void Test_Case_1_Columns() {
    matrix A(3, 4);

    bool passed = (A.columns() == 4);

    cout << "Columns Test: "
         << (passed ? "PASS" : "FAIL") << endl;
}


// Test case 1 for get().
// Checks that the correct elements are returned.
void Test_Case_1_Get() {
    matrix A(2, 3);

    A.set(0, 0, 5);
    A.set(1, 2, 10);

    bool passed = (
        A.get(0, 0) == 5 &&
        A.get(1, 2) == 10 &&
        A.get(0, 1) == 0
    );

    cout << "Get Test: "
         << (passed ? "PASS" : "FAIL") << endl;
}


// Test case 1 for set().
// Checks that the correct elements are updated.
void Test_Case_1_Set() {
    matrix A(2, 3);

    A.set(0, 0, 15);
    A.set(1, 2, 25);

    bool passed = (
        A.get(0, 0) == 15 &&
        A.get(1, 2) == 25 &&
        A.get(0, 1) == 0
    );

    cout << "Set Test: "
         << (passed ? "PASS" : "FAIL") << endl;
}


// Test case 1 for ~matrix().
// Checks that a dynamically allocated matrix can be deleted.

void Test_Case_1_Destructor() {
    matrix* A = new matrix(3, 3);

    A->set(0, 0, 10);
    A->set(2, 2, 20);

    bool passed = (
        A->get(0, 0) == 10 &&
        A->get(2, 2) == 20
    );

    delete A;

    cout << "Destructor Test : "
         << (passed ? "PASS" : "FAIL") << endl;
}


// Test case 1 for matrix operation +.
// Checks that corresponding elements are added correctly.
void Test_Case_1_Plus() {
    matrix A(2, 2);
    matrix B(2, 2);

    A.set(0, 0, 1);
    A.set(0, 1, 2);
    A.set(1, 0, 3);
    A.set(1, 1, 4);

    B.set(0, 0, 5);
    B.set(0, 1, 6);
    B.set(1, 0, 7);
    B.set(1, 1, 8);

    matrix C = A + B;

    bool passed = (
        C.get(0, 0) == 6 &&
        C.get(0, 1) == 8 &&
        C.get(1, 0) == 10 &&
        C.get(1, 1) == 12
    );

    cout << "Addition Test: "
         << (passed ? "PASS" : "FAIL") << endl;
}


// Test case 1 for matrix operation -.
// Checks that corresponding elements are subtracted correctly.
void Test_Case_1_Minus() {
    matrix A(2, 2);
    matrix B(2, 2);

    A.set(0, 0, 10);
    A.set(0, 1, 20);
    A.set(1, 0, 30);
    A.set(1, 1, 40);

    B.set(0, 0, 1);
    B.set(0, 1, 2);
    B.set(1, 0, 3);
    B.set(1, 1, 4);

    matrix C = A - B;

    bool passed = (
        C.get(0, 0) == 9 &&
        C.get(0, 1) == 18 &&
        C.get(1, 0) == 27 &&
        C.get(1, 1) == 36
    );

    cout << "Subtraction Test: "
         << (passed ? "PASS" : "FAIL") << endl;
}


// Test case 1 for matrix operation *.
// Checks that standard matrix multiplication gives the
// correct result using row-by-column multiplication.
void Test_Case_1_Multiply() {
    matrix A(2, 2);
    matrix B(2, 2);

    A.set(0, 0, 1);
    A.set(0, 1, 2);
    A.set(1, 0, 3);
    A.set(1, 1, 4);

    B.set(0, 0, 5);
    B.set(0, 1, 6);
    B.set(1, 0, 7);
    B.set(1, 1, 8);

    matrix C = A * B;

    bool passed = (
        C.rows() == 2 &&
        C.columns() == 2 &&
        C.get(0, 0) == 19 &&
        C.get(0, 1) == 22 &&
        C.get(1, 0) == 43 &&
        C.get(1, 1) == 50
    );

    cout << "Multiplication Test: "
         << (passed ? "PASS" : "FAIL") << endl;
}


// Test case 1 for matrix operation ~.
// Checks that transposing a 2x3 matrix gives a 3x2
// matrix with the correct elements.
void Test_Case_1_Transpose() {
    matrix A(2, 3);

    A.set(0, 0, 1);
    A.set(0, 1, 2);
    A.set(0, 2, 3);
    A.set(1, 0, 4);
    A.set(1, 1, 5);
    A.set(1, 2, 6);

    matrix B = ~A;

    bool passed = (
        B.rows() == 3 &&
        B.columns() == 2 &&
        B.get(0, 0) == 1 &&
        B.get(0, 1) == 4 &&
        B.get(1, 0) == 2 &&
        B.get(1, 1) == 5 &&
        B.get(2, 0) == 3 &&
        B.get(2, 1) == 6
    );

    cout << "Transpose Test: "
         << (passed ? "PASS" : "FAIL") << endl;
}


// Test case 1 for matrix operation ==.
// Checks that identical matrices return true and
// matrices with different values or dimensions return false.
void Test_Case_1_Equals() {
    matrix A(2, 2);
    matrix B(2, 2);

    A.set(0, 0, 1);
    A.set(0, 1, 2);
    A.set(1, 0, 3);
    A.set(1, 1, 4);

    B.set(0, 0, 1);
    B.set(0, 1, 2);
    B.set(1, 0, 3);
    B.set(1, 1, 4);

    // Identical matrices should be equal.
    bool passed = (A == B);

    // Changing one element should make them unequal.
    B.set(1, 1, 10);

    if (A == B) {
        passed = false;
    }

    // Different-sized matrices should not be equal.
    matrix C(3, 3);

    if (A == C) {
        passed = false;
    }

    cout << "Equality Test: "
         << (passed ? "PASS" : "FAIL") << endl;
}


// Test case 1 for toStr().
// Checks that the string contains every element,
// with spaces between columns and newlines between rows.
void Test_Case_1_ToStr() {
    matrix A(2, 3);

    A.set(0, 0, 1);
    A.set(0, 1, 2);
    A.set(0, 2, 3);
    A.set(1, 0, 4);
    A.set(1, 1, 5);
    A.set(1, 2, 6);

    string expected = "1 2 3\n4 5 6";

    bool passed = (A.toStr() == expected);

    cout << "ToStr Test: "
         << (passed ? "PASS" : "FAIL") << endl;

    cout << "Matrix contents:" << endl;
    cout << A.toStr() << endl;
}


// Run all test cases.
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
    Test_Case_1_Plus();
    Test_Case_1_Minus();
    Test_Case_1_Multiply();
    Test_Case_1_Transpose();
    Test_Case_1_Equals();
    Test_Case_1_ToStr();

    return 0;
}
