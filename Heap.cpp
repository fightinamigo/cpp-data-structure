#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
    vector<int> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int leftChild(int i) {
        return 2 * i + 1;
    }

    int rightChild(int i) {
        return 2 * i + 2;
    }

    void swap(int index1, int index2) {
        int tmp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = tmp;
    }

public:
    void printHeap() {
        cout << "\n[";
        for (size_t i = 0; i < heap.size(); i++) {
            cout << heap[i];
            if (i < heap.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    void insert(int value) {
        heap.push_back(value);
        int current = heap.size() - 1;

        while (current > 0 && heap[current] > heap[parent(current)]) {
            swap(current, parent(current));
            current = parent(current);
        }
    }

    void sinkDown(int index) {
        int maxIndex = index;
        while (true) {
            int leftIndex = leftChild(maxIndex);
            int rightIndex = rightChild(maxIndex);

            if (leftIndex < heap.size() && heap[rightIndex] > heap[maxIndex]) {
                maxIndex = rightIndex;
            }

            if (rightIndex < heap.size() && heap[leftIndex] > heap[maxIndex]) {
                maxIndex = leftIndex;
            }

            if (maxIndex != index) {
                swap(index, maxIndex);
                index = maxIndex;
            } else {
                return;
            }

        }
    }
    int remove() {
        if (heap.empty()) {
            return INT_MIN;
        }

        if (heap.size() == 1) {
            int maxValue = heap.front();
            heap.clear();
            return maxValue;
        }

        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        sinkDown(0);

        return maxValue;
    }


};




int main() {
    Heap* heap = new Heap();

    heap->insert(1);
    heap->insert(2);
    heap->insert(3);
    heap->insert(4);
    heap->insert(5);
    heap->insert(6);


    heap->printHeap();

    heap->remove();

    heap->printHeap();

    heap->remove();
    heap->printHeap();


    return 0;
}