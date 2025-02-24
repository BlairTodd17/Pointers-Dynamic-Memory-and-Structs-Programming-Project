#include <iostream>
using namespace std;

// Function to reverse an array
int* reverseArray(const int* arr, int size) {
    int* reversedArr = new int[size];
    for (int i = 0; i < size; i++) {
        reversedArr[i] = arr[size - 1 - i];
    }
    return reversedArr;
}

void testReverseArray() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = 5;
    int* reversedArr = reverseArray(arr, size);

    cout << "Original Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Reversed Array: ";
    for (int i = 0; i < size; i++) {
        cout << reversedArr[i] << " ";
    }
    cout << endl;

    delete[] reversedArr;
}

int main() {
    cout << "Testing Reverse Array:" << endl;
    testReverseArray();
    return 0;
}