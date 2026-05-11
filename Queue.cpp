#include <iostream>



using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class Queue {
    private:
        Node* first;
        Node* last;
        int length;
    public:
        Queue(int value) {
            Node* newNode = new Node(value);
            newNode->next = nullptr;
            first = newNode;
            last = newNode;
            length = 1;
        }

        void printQueue() {
            Node* temp = first;
            if (temp == nullptr) {
                cout << "Empty Queue" << endl;
            }
            else {
                while (temp) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp) {
                        cout << "->";
                    }
                }
            }
            cout << endl;
        }

        void getFirst() {
            cout << "First: " << first->value << endl;
        }

        void getLast() {
            cout << "Last: " << last->value << endl;
        }

        void getLength() {
            cout << "Length: " << length << endl;
        }

        void enqueue(int value) {
            Node* newNode = new Node(value);
            if (first == nullptr) {
                first = newNode;
                last = newNode;
            }
            else {
                last->next = newNode;
                last = newNode;
            }
            length++;
        }

        int dequeue() {
            if (first == nullptr) {
                cout << "Empty Queue" << endl;
                return INT_MIN;
            }
            Node* temp = first;
            int dequeuedValue = first->value;
            if (length == 1) {
                first = nullptr;
                last = nullptr;
            }
            else {
                first = first->next;
            }
            delete temp;
            length--;
            return dequeuedValue;
        }

        // enqueue using two stacks
        // void enqueue(int value) {
        //     stack1.push(value);
        // }

        // dequeue using two stacks
        // int dequeue(){
        //         int dvalue = front();
        //         if (dvalue == INT_MIN){
        //             cout << "queue is empty" << endl;
        //             return INT_MIN;
        //         }
        //         stack2.pop();
        //         return dvalue;
        //
        //     }

};



int main() {
    Queue *myQueue = new Queue(0);
    myQueue->enqueue(1);
    myQueue->enqueue(2);
    myQueue->enqueue(3);
    myQueue->enqueue(4);

    myQueue->printQueue();

    myQueue->getFirst();
    myQueue->getLast();
    myQueue->getLength();

    cout << "dequeued value: " << myQueue->dequeue() << endl;

    myQueue->printQueue();
    myQueue->getFirst();
    myQueue->getLast();
    myQueue->getLength();

    return 0;
}