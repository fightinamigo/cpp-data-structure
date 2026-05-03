#include <iostream>

using namespace std;

/* Thats an example of recursion */
int factorial(int n){
        if (n == 1) return 1;
        return n * factorial(n - 1);
    }

int main() {
    cout << factorial(4);
}