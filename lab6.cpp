#include <iostream>

using namespace std;

double calculateSeries(int n) {
    if (n == 1) {
        return 1.0;
    }
    
    double currentTerm;
    if (n % 2 == 0) {
        currentTerm = -1.0 / n;
    } else {
        currentTerm = 1.0 / n;
    }
    
    return currentTerm + calculateSeries(n - 1);
}

int main() {
    int n;
    cout << "n degerini giriniz: ";
    cin >> n;
    
    if (n > 0) {
        double result = calculateSeries(n);
        cout << "Sonuc: " << result << endl;
    } else {
        cout << "Lutfen pozitif bir tam sayi giriniz." << endl;
    }
    
    return 0;
}

