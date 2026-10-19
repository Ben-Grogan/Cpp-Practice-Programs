#include <iostream>
using namespace std;


/*
This function takes in a character array to act as a string. it then
calls the length function with said array which initialises an int variable "count".
using count as the string index, while the value at count does not equal
\0, count is incremented. count is then returned and printed.
*/



// function to count length of a string
unsigned int length (const char* str){


    // unsigned as the string can't be negative length
    unsigned int count = 0;


    //while the index is not at end of string, increment count.
    while(str[count] != '\0'){
        count++;
    }

    return count;


}

//TEST CASES

// normal string
void length_test_case_1(){
    cout << "Length Test 1: " << (length("hello") == 5 ? "PASS" : "FAIL") << endl;
}

//empty string
void length_test_case_2(){
    cout << "Length Test 2: " << (length("") == 0 ? "PASS" : "FAIL") << endl;
}

//string with spaces
void length_test_case_3(){
    cout << "Length Test 3: " << (length("hello world") == 11 ? "PASS" : "FAIL") << endl;
}

//single character
void length_test_case_4(){
    cout << "Length Test 4: " << (length("x") == 1 ? "PASS" : "FAIL") << endl;
}



//call function and output result
int main(){
    
    //call test cases
    length_test_case_1();
    length_test_case_2();
    length_test_case_3();
    length_test_case_4();

    char str[] = "a";

    cout << length(str) << endl;

    
    return 0;


}