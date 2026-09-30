#include <iostream>
using namespace std;


bool powerOfTwo(int num){
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