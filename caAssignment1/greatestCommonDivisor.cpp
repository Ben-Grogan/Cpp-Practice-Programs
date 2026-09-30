#include <iostream>
using namespace std;

int main(){

 int num1;
    int num2;
    int rem;
    int lastrem;
    cin >> num1;
    cin >> num2; 

    while(rem>0){

        lastrem = rem;
        if(num1 > num2){
            rem = num1%num2;
            num1=num2;
            num2=rem;
        }
        else if(num2 > num1){
            rem = num2%num1;
            num2 = num1;
            num1 = rem;
        }
        
        
    }

    cout << lastrem;
    return 0;

}
   
