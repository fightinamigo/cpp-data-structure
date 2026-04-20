#include <iostream>

using namespace std;





void bubble_sort(int arr[], int size) {
    for (int i = size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int minIndex = i;
        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (i != minIndex) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int temp = arr[i];
        int j = i - 1 ;
        while (j > -1 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}







int main() {

    int myArray[] = {6,4,2,5,1,3} ;
    int size = sizeof(myArray) / sizeof(myArray[0]);

    cout << "Before Bubble sort: " << endl;
    for (auto value : myArray) {
        cout << value << " ";
    }
    cout << endl;
    cout << "After Bubble Sort: " << endl;
    bubble_sort(myArray, size);
    for (auto value : myArray) {
        cout << value << " ";
    }

    cout << endl;
    cout << "----------------------------------";
    cout << endl;

    int myArray1[] = {6,4,2,5,1,3} ;
    int size1 = sizeof(myArray1) / sizeof(myArray1[0]);

    cout << "Before Selection sort: " << endl;
    for (auto value : myArray1) {
        cout << value << " ";
    }
    cout << endl;
    cout << "After Selection sort:" << endl;
    selection_sort(myArray1, size1);
    for (auto value : myArray1) {
        cout << value << " ";
    }

    cout << endl;
    cout << "----------------------------------";
    cout << endl;

    int myArray2[] = {6,4,2,5,1,3} ;
    int size2 = sizeof(myArray2) / sizeof(myArray2[0]);

    cout << "Before Insertion sort: " << endl;
    for (auto value : myArray2) {
        cout << value << " ";
    }
    cout << endl;
    cout << "After Insertion sort: " << endl;
    insertion_sort(myArray2, size2);
    for (auto value : myArray2) {
        cout << value << " ";
    }

    return 0;
}