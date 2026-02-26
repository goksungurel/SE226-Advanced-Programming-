#include <iostream>
#include <string>
#include <cmath> 

using namespace std;

int main() {
   //1
    string name;
    string id;

    cout << "What is your name?\n";
    cin >> name;
    cout << "Hello " << name << ".\n";

    cout << "What is your Student ID?\n";
    cin >> id;
    cout << "Your ID is: " << id << "\n\n";


   //2
    int total_number;
    cout << "Enter a total number of seconds: ";
    cin >> total_number;

    int hours = total_number / 3600;
    int remaining_seconds = total_number % 3600;
    int minutes = remaining_seconds / 60;
    int seconds = remaining_seconds % 60;

    cout << total_number << " seconds is " << hours << " hours, " 
         << minutes << " minutes, and " << seconds << " seconds.\n\n";


   //3
    double x1, y1, x2, y2; 

    cout << "Enter x1: ";
    cin >> x1;
    cout << "Enter y1: ";
    cin >> y1;
    
    cout << "Enter x2: ";
    cin >> x2;
    cout << "Enter y2: ";
    cin >> y2;

    
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    cout << "Distance = " << distance << "\n\n";


   //4
    cout << "*******\n *****\n  ***\n   *\n";

    return 0; 
}
