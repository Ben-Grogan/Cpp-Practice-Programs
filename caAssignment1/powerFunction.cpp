#include <iostream>
using namespace std;

int powerFunction(int x, int y){
    int answer = 1;

    while(y > 0){
        if(y%2 == 1){
            answer *= x;
        }

        x *= x;

        /*
        This line is the reason this has a time complexity
        of O(log n), as the exponent is being halved each
        iteration. even if the exponent was 1million, it
        would only take 20 or so iterations, as opposed to
        a million iterations for the alternative.
        */
        y /= 2;
    }

    return answer;

}

int main(){
    int x;
    int y;

    cout << "Please enter a base number and an exponent (in that order)" << endl;

    cin >> x;

    cin >> y;

    int power = powerFunction(x,y);
    
    cout << power;

    return 0;
}