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
        // remembers last remainder so it doesn't equal 0 at the end
        lastrem = rem;

        //if and else clause used so the order of inputs doesnt matter
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
        
        /*
        uses euclids algorithm to determine the greatest common divisor,
        each iteration finds the remainder of a/b, then sets a to b, and
        b to the remainder. repeat this and the last non 0 remainder is the
        greatest common divisor.     
        */
        
    }

    cout << lastrem;
    return 0;

}
   
