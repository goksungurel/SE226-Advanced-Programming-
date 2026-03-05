#include <iostream>
using namespace std;
#include <cmath>

int main() {
  //task 1
    int n, steps = 0;
    cout << "Enter greater than 1: ";
    cin >> n;

    cout << n;
    while (n != 1) {
        if (n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
        
        cout << " -> " << n;
        steps++;
    }
    cout << "\nTotal Steps: " << steps << endl;

//task 2
  int n;
    while (true) {
        cout << "Please enter a number between 10 and 100: ";
        cin >> n;
        if (n >= 10 && n <= 100) break;
        cout << "invalid!" << endl;
    }

    int f = 0, b = 0, fb = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 7 == 0) continue;

        if (i % 3 == 0 && i % 5 == 0) {
            cout << "FizzBuzz" << endl;
            fb++;
        } else if (i % 3 == 0) {
            cout << "Fizz" << endl;
            f++;
        } else if (i % 5 == 0) {
            cout << "Buzz" << endl;
            b++;
        } else {
            cout << i << endl;
        }
    }
    cout << "Fizz: " << f << " Buzz: " << b << " FizzBuzz: " << fb << endl;

//task 3 
  int n;
    cout << "Please enter a number between 3 and 9: ";
    cin >> n;

    for (int i = 1; i < 2 * n; i++) {
        int yildiz_sayisi = n - abs(n - i);
        for (int j = 0; j < yildiz_sayisi; j++) {
            cout << "*";
        }
        cout << endl;
    }



  
    return 0;
}
