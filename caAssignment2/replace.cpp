#include <iostream>

//INCLUDED ONLY FOR TEST CASES//
#include <cstring>

using namespace std;




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

/*
This function takes in 3 things, a character to replace C, the charachter to replace it with P
and the string to replace characters within STR. first a new char array dest is created which is one character
bigger than str to account for \0. it then copies the contents of str to dest, but replaces any occurence of C with
P. if no occurence of C is found it works as the previous copy function. dest is then returned and printed.
*/

char* replace (char c, char p, const char* str){
    
    char* dest = new char[length(str)+1];



    int i = 0;
    //while loop replaces dest with contents of str, and replaces characters where necessary
    while (str[i] != '\0'){
        
        if(str[i] == c){
            dest[i] = p;
            i++;
        }
        else{
            dest[i] = str[i];
            i++;
        }
        
    }

    //ends the string
    dest[i] = '\0';

    return dest;
}



//TEST CASES

// normal string
void replace_test_case_1(){
    char str[] = "string";

    char* result = replace('i', 'x', str);

    cout << "Test 1: " << (strcmp(result, "strxng") == 0 ? "PASS" : "FAIL") << endl;

    delete[] result;
}

//empty string
void replace_test_case_2(){
    char str[] = "";

    char* result = replace('a', 'x', str);

    cout << "Test 2: " << (strcmp(result, "") == 0 ? "PASS" : "FAIL") << endl;

    delete[] result;

}

//string with spaces
void replace_test_case_3(){
    char str[] = "hello world";

    char* result = replace(' ', '-', str);

    cout << "Test 3: " << (strcmp(result, "hello-world") == 0 ? "PASS" : "FAIL") << endl;

    delete[] result;
}

//single character
void replace_test_case_4(){

    char str[] = "a";

    char* result = replace('a', 'b', str);

    cout << "Test 4: " << (strcmp(result, "b") == 0 ? "PASS" : "FAIL") << endl;

    delete[] result;

}

// Multiple occurrences of character
void replace_test_case_5() {
    char str[] = "banana";

    char* result = replace('a', 'o', str);

    cout << "Test 5: " << (strcmp(result, "bonono") == 0 ? "PASS" : "FAIL") << endl;

    delete[] result;
}

// Character not found
void replace_test_case_6() {
    char str[] = "hello";

    char* result = replace('z', 'x', str);

    cout << "Test 6: " << (strcmp(result, "hello") == 0 ? "PASS" : "FAIL") << endl;

    delete[] result;
}



//call function and output result
int main(){
    
    char str[] = "string";
    //call test cases
    replace_test_case_1();
    replace_test_case_2();
    replace_test_case_3();
    replace_test_case_4();
    replace_test_case_5();
    replace_test_case_6();

    cout << replace('i', 'x', str) << endl;

    
    return 0;


}