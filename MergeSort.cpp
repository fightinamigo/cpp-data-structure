#include <iostream>

using namespace std;



void Merge(int arr[], int leftIndex, int midIndex, int rightIndex) {
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;

    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    for (int i = 0; i < leftArraySize; i++)
        leftArray[i] = arr[leftIndex + i];
    for (int j = 0; j < rightArraySize; j++)
        rightArray[j] = arr[midIndex + 1 + j];

    int index = leftIndex;
    int i = 0;
    int j = 0;

    while (i < leftArraySize && j < rightArraySize) {
        if (leftArray[i] <= rightArray[j]) {
            arr[index] = leftArray[i];
            index++;
            i++;
        }
        else {
            arr[index] = rightArray[j];
            index++;
            j++;
        }
    }

    while (i < leftArraySize) {
        arr[index] = leftArray[i];
        index++;
        i++;
    }

    while (j < rightArraySize) {
        arr[index] = rightArray[j];
        index++;
        j++;
    }
}

void MergeSort(int arr[], int leftIndex, int rightIndex) {
    if (leftIndex >= rightIndex)return;

    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
    MergeSort(arr, leftIndex, midIndex);
    MergeSort(arr, midIndex+1, rightIndex);

    Merge(arr, leftIndex, midIndex, rightIndex);
}



int main() {
    int myArr[] = {1,3,5,7,2,4,6,8};

    int size = sizeof(myArr) / sizeof(myArr[0]);
    int leftIndex = 0;
    int rightIndex = size - 1;
    int midIndex = (size / 2) - 1;

    cout << "Before Merge: " << endl;
    for (auto value : myArr) {
        cout << value << " ";
    }
    cout << endl;
    Merge(myArr, leftIndex, midIndex, rightIndex);
    cout << "After Merge: " << endl;
    for (auto value : myArr) {
        cout << value << " ";
    }

    cout << endl << endl;

    int myArr2[] = {3,1,4,2};

    size = sizeof(myArr2) / sizeof(myArr2[0]);
    int leftIndex2 = 0;
    int rightIndex2 = size - 1;

    cout << "Before Merge Sorting: " << endl;
    for (auto value : myArr2) {
        cout << value << " ";
    }
    cout << endl;
    MergeSort(myArr2, leftIndex2, rightIndex2);
    cout << "After Merge Sorting: " << endl;
    for (auto value : myArr2) {
        cout << value << " ";
    }




    return 0;
}