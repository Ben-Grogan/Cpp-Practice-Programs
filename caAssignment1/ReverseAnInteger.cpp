#include <iostream>
using namespace std;

int reverseDigits(int num){
    int rev = 0;

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


