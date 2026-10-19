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
This Function takes in a char array str and a range of indexes that contain
a desired substring (i and j). The function loops through the indexes from i to j
and returns adds the characters contained within the range to a result array. this
array is returned and printed. if the range is outside of the string null is returned
*/


char* substring (int i, int j, const char* str){
    
    char* result = new char[j - i + 2];

    if(i < 0 || j > length(str) || j < i){
        return NULL;
    }

    while(i < j){
        result[i] = str[i];
        i++;
    }  

    return result;
}



//TEST CASES

//regular string
void substring_test_case_1(){

    char str[] = "string";

    char* result = substring(0, 3, str);

    cout << (strcmp(result, "str") == 0 ? "PASS" : "FAIL") << endl;

    //delete[] result;
}

//empty string
void substring_test_case_2(){

    char str[] = "";

    cout << (substring(0, 1, str) == NULL ? "PASS" : "FAIL") << endl;

}

//string with spaces
void substring_test_case_3(){

    char str[] = "hello world";

    char* result = substring(0, 5, str);

    cout << (strcmp(result, "hello") == 0 ? "PASS" : "FAIL") << endl;

}

//single character
void substring_test_case_4(){

    char str[] = "x";

    char* result = substring(0, 1, str);

    cout << (strcmp(result, "x") == 0 ? "PASS" : "FAIL") << endl;

}



//call function and output result
int main(){
   
    char str[] = "string";

    substring_test_case_1();
    substring_test_case_2();
    substring_test_case_3();
    substring_test_case_4();
    
    if(substring(0, 3, str) != NULL){
        cout << substring(0, 3, str) << endl;
    }
    else{
        cout << "INVALID" << endl;
    }


    return 0;
}    