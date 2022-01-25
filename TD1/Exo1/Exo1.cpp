
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    for (;;) {
        cout << "Entrer un nombre entier : "<<endl;
        int x;
        cin >> x;

        bool isPrime = true;

        
        for (int i = 3; i <= sqrt(x); ++i) {
            if (x % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            cout << "Ce nombre est premier"<<endl;
        }
        else{
        
    }
}

