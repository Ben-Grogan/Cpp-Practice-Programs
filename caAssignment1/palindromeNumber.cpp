#include <iostream>

using namespace std;

bool checkPalindrome(int num){
    
    if(num<0){
        return false;
    }

    int rev = 0;
    int compare = num;

    while(num>0){
        rev = rev*10+num%10;
        num=num/10;
    }

    if(rev == compare){
        return true;
    }

    return false;
}

int main(){

    int num;

    cout << "Please enter a number to check if it's a palindrom" << endl;
    cin >> num;

    bool isPalindrome = checkPalindrome(num);

    if(isPalindrome == true){
        cout << "true";
    }
    else{
        cout << "false";
    }


    return 0;
}