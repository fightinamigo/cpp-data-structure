#include <iostream>
using namespace std;

// ─────────────────────────────────────────
//  1. LINEAR SEARCH
// ─────────────────────────────────────────
int linearSearch(int a[], int length, int target) {
    for (int n = 0; n < length; n++) {
        if (a[n] == target) {
            return n;    // Found: return index
        }
    }
    return -1;           // Not found
}

void runLinearSearch() {
    int a[] = {10, 25, 33, 47, 58};
    int length = sizeof(a) / sizeof(a[0]);
    int target = 33;

    cout << "=== Linear Search ===" << endl;
    cout << "Array: ";
    for (int i = 0; i < length; i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "Target: " << target << endl;

    int result = linearSearch(a, length, target);
    if (result != -1)
        cout << "Found at index: " << result << endl;
    else
        cout << "Not found." << endl;
}

// ─────────────────────────────────────────
//  2. BINARY SEARCH
// ─────────────────────────────────────────
int binarySearch(int a[], int low, int high, int target) {
    int mid;
    while (high >= low) {
        mid = (high + low) / 2;    // Calculate midpoint

        if (target < a[mid])        // Target is in lower half
            high = mid - 1;
        else if (target > a[mid])   // Target is in upper half
            low = mid + 1;
        else
            return mid;             // Found: return index
    }
    return -1;                      // Not found
}

void runBinarySearch() {
    int a[] = {10, 25, 33, 47, 58};  // Must be sorted for binary search
    int length = sizeof(a) / sizeof(a[0]);
    int target = 33;

    cout << "\n=== Binary Search ===" << endl;
    cout << "Array: ";
    for (int i = 0; i < length; i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "Target: " << target << endl;

    int result = binarySearch(a, 0, length - 1, target);
    if (result != -1)
        cout << "Found at index: " << result << endl;
    else
        cout << "Not found." << endl;
}

// ─────────────────────────────────────────
//  MAIN
// ─────────────────────────────────────────
int main() {
    runLinearSearch();
    runBinarySearch();
    return 0;
}
