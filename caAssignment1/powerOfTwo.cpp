#include <iostream>
using namespace std;


bool powerOfTwo(int num){

/*
this ones super simple, the algorithm just divides the 
input by 2 until the remainder is not 0, as this would
mean it's not divisible by two. if the input reaches 1
then it is a power of 2.

*/

    if (num <= 0){
        return false;
    }

    while(num >1){
        if(num%2 != 0){
            return false;
        }
        num=num/2;
    }

    return true;
}

int main(){
    int num;

    cout << "Please enter a number to check if it's a power of two" << endl;
    cin >> num;


    bool answer = powerOfTwo(num);

    if (answer == true){
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;


}