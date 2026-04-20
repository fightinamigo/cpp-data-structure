#include <iostream>
using namespace std;

// ─────────────────────────────────────────
//  SHELL SORT
// ─────────────────────────────────────────
void shellSort(int arr[], int length) {
    int gap, i, j, temp;
    for (gap = length / 2; gap > 0; gap /= 2)
        for (i = gap; i < length; i++)
            for (j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap) {
                temp = arr[j];
                arr[j] = arr[j + gap];
                arr[j + gap] = temp;
            }
}

void runShellSort() {
    int arr[] = {64, 25, 12, 22, 11};
    int length = sizeof(arr) / sizeof(arr[0]);

    cout << "=== Shell Sort ===" << endl;
    cout << "Before: ";
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << endl;

    shellSort(arr, length);

    cout << "After:  ";
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ─────────────────────────────────────────
//  MAIN
// ─────────────────────────────────────────
int main() {
    runShellSort();
    return 0;
}
