#include <iostream>
using namespace std;


/*
This function takes in a character to find in a string C, and a string to find the character
in str. the function is called and the string is traversed until c is found. once c is found,
the index is returned. if C is not found -1 is returned as the index, noting that c is not in the string
*/


// Function to get the index of a character in a string
int indexOf (char c, const char* str){

    int i = 0;

    while(str[i] != '\0'){
        if(str[i] == c){
            return i;
        }
        i++;
    }

    return -1;

}


//TEST CASES

//regular string
void indexOf_test_case_1(){
    char str[] = "michelle";
    cout << (indexOf('c', str) == 2 ? "PASS" : "FAIL" ) << endl;
}

//empty string
void indexOf_test_case_2(){
    char str[] = "";
    cout << (indexOf('c', str) == -1 ? "PASS" : "FAIL" ) << endl;
}

//string with spaces
void indexOf_test_case_3(){
    char str[] = "hello world";
    cout << (indexOf('w', str) == 6 ? "PASS" : "FAIL" ) << endl;
}

//single character
void indexOf_test_case_4(){
    char str[] = "a";
    cout << (indexOf('a', str) == 0 ? "PASS" : "FAIL" ) << endl;
}



//call function and output result
int main(){
   
    char str[] = "michelle";

    indexOf_test_case_1();
    indexOf_test_case_2();
    indexOf_test_case_3();
    indexOf_test_case_4();
    
    if(indexOf('c', str) != -1){
        cout << indexOf('c', str) << endl;
    }
    else{
        cout << "There is no C in the sring";
    }
    return 0;


}