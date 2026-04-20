#include <iostream>

using namespace std;



int BinarySearch(int arr[],int SearchKey,int first,int last) {
    int index;
    if (first > last) {
        return -1;
    }
    else {
        int mid = (first + last) / 2;
        if (arr[mid] == SearchKey) {
            index = mid;
        }
        else if (SearchKey < arr[mid]) {
            BinarySearch(arr, mid -1, SearchKey,first);
        }
        else {
            BinarySearch(arr, SearchKey, mid+1, last);
        }
        return index;
    }
}


int main() {
    int array[] = {2, 5, 8, 12, 16, 23, 38};
    int size = 7;
    int key;

    cout << "Enter number to search: ";
    cin >> key;

    int result = BinarySearch(array, 0, size - 1, key);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}


