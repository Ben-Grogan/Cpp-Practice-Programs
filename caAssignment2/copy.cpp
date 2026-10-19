#include <iostream>
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
This function takes in a char array src and another array dest which src is to be copied to
dest has a defined size and if src wont fit within dest, null is returned. Otherwise, the contents
of src are copied into dest using a while loop, and once src has been traversed fully, \0 is inserted
to end the string. this ensures the filler letters in the initial dest array dont show up in the final
result. dest is returned and printed.
*/

//function to copy a string to another string, if the length permits it.
char* copy (char* dest, const char* src){

    //if dest is shorter than src, it wont fit string. Returns NULL
    if (length(dest) < length(src)){
        return NULL;
    }

    int i = 0;
    //while loop replaces dest with contents of src
    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }

    //ends the string
    dest[i] = '\0';

    return dest;

}
//TEST CASES

//regular string
void copy_test_case_1(){
    char dest[20] = "aaaaaaaaaaaaaaaaaaa";

    cout << (copy(dest,"hello") != NULL && length(dest) == 5 ? "PASS" : "FAIL") << endl;
}

//empty string
void copy_test_case_2(){
    char dest[1] = "";

    cout << (copy(dest,"hello") == NULL ? "PASS" : "FAIL") << endl;
}

//string with spaces
void copy_test_case_3(){
    char dest[10] = "aaaaaaaaa";

    cout << (copy(dest,"hey world") != NULL && length(dest) == 9 ? "PASS" : "FAIL") << endl;
}

//short string
void copy_test_case_4(){
    char dest[2] = "a";

    cout << (copy(dest,"b") != NULL && length(dest) == 1 ? "PASS" : "FAIL") << endl;
}



//call function and output result
int main(){
    
    //call test cases
    copy_test_case_1();
    copy_test_case_2();
    copy_test_case_3();
    copy_test_case_4();


    char dest[20] = "aaaaaaaaaaaaaaaaaaa";

    if (copy(dest, "hello") != NULL) {
        cout << dest << endl;
    }
    else{
        cout << "Not Enough Space" << endl;
    }


    
    
    return 0;


}