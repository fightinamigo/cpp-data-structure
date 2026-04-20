#include <iostream>

using namespace std;
            // Another quick solution //
void quick_sort(int array[], int left, int right) {
    int i = left, j = right;
    int pivot = array[(left+right)/2];
    while (i <= j) {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;
        if (i <= j) {
            int temp = array[i];
            array[i]= array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j) {
        quick_sort(array, left, j);
    }
    if (right > i) {
        quick_sort(array, i, right);
    }
}









void swap(int array[],int firstIndex, int secondIndex) {
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

int pivot(int array[], int pivotIndex, int endIndex ) {
    int swapIndex = pivotIndex;
    for (int i = pivotIndex+1; i <= endIndex; i++) {
        if (array[i] < array[pivotIndex]) {
            swapIndex++;
            swap(array,swapIndex,i);
        }

    }
    swap(array,pivotIndex,swapIndex);
    return swapIndex;
}

void quickSort(int array[], int leftIndex, int rightIndex) {
    if (leftIndex >= rightIndex)return;

    int pivotIndex = pivot(array, leftIndex, rightIndex);
    quickSort(array, leftIndex, pivotIndex-1);
    quickSort(array, pivotIndex+1, rightIndex);
}


int main() {
    int myArray[] = {4,6,1,7,3,2,5};

    int size = sizeof(myArray) / sizeof(myArray[0]);

    cout << "Before pivot: " << endl;
    for (auto value : myArray) {
        cout << value << " ";
    }
    cout << endl;
    cout << "After pivot: " << endl;
    cout << "swapIndex:" << pivot(myArray, 0, size - 1) << endl;
    for (auto value : myArray) {
        cout << value << " ";
    }

    cout << endl << endl;

    int myArray1[] = {4,6,1,7,3,2,5};

    int size1 = sizeof(myArray1) / sizeof(myArray1[0]);

    cout << "Before quickSort: " << endl;
    for (auto value : myArray1) {
        cout << value << " ";
    }
    cout << endl;
    quickSort(myArray1, 0, size - 1);
    cout << "After quickSort: " << endl;
    for (auto value : myArray1) {
        cout << value << " ";
    }
}

