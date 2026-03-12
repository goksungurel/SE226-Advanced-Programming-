#include <iostream>
using namespace std;
int* createArray(int size) { 
    int* arr = new int[size];
    return arr;
}
void deleteArray(int* arr) { 
    delete[] arr;
    cout << "Memory released successfully." << endl; 
}
void swapValues(int* p1,int* p2){
    int temp=*p1;
    *p1=*p2;
    *p2=temp;
}
void printArray(int* arr,int size){
    for(int i=0;i<size;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}
int findSum(int* arr,int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+= *(arr+i);
    }
    return sum;
}
void shiftRight(int* arr, int size) {
    if (size <= 1) return;
    int lastElement = *(arr + size - 1); 
    for (int i = size - 1; i > 0; i--) {
        *(arr + i) = *(arr + i - 1); 
    }
    *arr = lastElement; 
}

int main() {
    int size;
    cout << "Creating dynamic array." << endl; 
    cout << "Enter array size: "; 
    cin >> size;

    int* myArr = createArray(size); 

    cout << "Enter values: "; 
    for (int i = 0; i < size; i++) {
        cin >> *(myArr + i);
    }

    cout << "Array elements: " << endl; 
    printArray(myArr, size);
    cout << "Sum of elements: " << findSum(myArr, size) << endl; 

    int a = 5, b = 8; 
    cout << "Swapping two numbers" << endl; 
    cout << "Before swap: a=" << a << " b=" << b << endl; 
    swapValues(&a, &b); 
    cout << "After swap: a=" << a << " b=" << b << endl; 


    cout << "Shifting array to the right..." << endl; 
    shiftRight(myArr, size); 
    cout << "Array after shiftRight: " << endl; 
    printArray(myArr, size); 

    
    cout << "Deleting array..." << endl; 
    deleteArray(myArr); 

    return 0;
}
