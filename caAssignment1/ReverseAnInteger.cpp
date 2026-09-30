#include <iostream>
using namespace std;

int reverseDigits(int num){
    int rev = 0;

    /*
    
    this algorithm uses the modulo operator to find the last
    digit of an integer, adds this to the reverse integer,
    divides the original integer by 10, and repeats until the
    whole integer is reversed. if theres a negative number, it
    makes it positive, does the calculation, then makes it negative
    again.
    
    */
    while(num>0){
        rev = rev*10+num%10;
        num=num/10;
    }

    if(num<0){
        num = num*-1;

        while(num>0){
            rev = rev*10+num%10;
            num=num/10;
        }

        rev = rev*-1;

    }

    return rev;
}


int main(){
    int num;

    cout << "Please Enter a number to reverse" << endl;
    cin >> num;
    cout << reverseDigits(num);

    return 0;
}


