#include <iostream>

using namespace std;


class Node {
    public:
    int value;
    Node* next;
    Node* prev;

    Node(int val) {
        this->value = val;
        next = nullptr;
        prev = nullptr;
    }
};



class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;
    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }
                    // No tail append
        // void appendo(int value) {
        //     Node* newNode = new Node(value);
        //     if (head == nullptr) {
        //         head = newNode;
        //     }
        //     else {
        //         Node* temp = head;
        //         while (temp->next) {
        //             temp = temp->next;
        //         }
        //         newNode->prev = temp;
        //         temp->next = newNode;
        //         newNode->next = nullptr;
        //     }
        // }

        void deleteLast () {
            if (head == nullptr) {
                cout << "empty";
                return;
            }
            Node* temp = tail;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            }else {
                tail = tail->prev;
                tail->next = nullptr;
            }
            delete temp;
            length--;
        }

                // No tail delete last
        // void deletelast() {
        //     if (head == nullptr) {
        //         cout << "empty";
        //         return;
        //     }
        //     Node* temp = head;
        //     if (length == 1) {
        //         head = nullptr;
        //     }
        //     else {
        //         while (temp->next) {
        //             temp = temp->next;
        //         }
        //     }
        //     delete temp;
        //     length--;
        // }

        void prepend(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            }
            else {
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
            }
            length++;
        }

        void deleteFirst() {
            if (head == nullptr) {
                cout << "empty";
                return;
            }
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            }else {
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;
            length--;
        }

        int getLength() {
            return length;
        }

        //Works for both SLL and DLL
        // Node* Get(int index) {
        //         if (index < 0 || index > length) {
        //             cout << "index out of bound";
        //             return nullptr;
        //         }
        //         Node* temp = head;
        //         for (int i = 0; i < index; i++) {
        //             temp = temp->next;
        //         }
        //         return temp;
        //     }

        //Works more efficiently with DLL
        Node* get(int index) {
            if (index < 0 || index > length) {
                cout << "index out of bound";
                return nullptr;
            }
            Node* temp = head;
            if (index < length/2) {
                for (int i = 0; i < index; i++) {
                temp = temp->next;
                }
            }else {
                temp = tail;
                for (int i = length - 1; i >= index; i--) {
                    temp = temp->prev;
                }
            }
            return temp;
        }

        bool set(int index, int value) {
            Node* temp = get(index);
            if (temp) {
                temp->value = value;
                return true;
            }
            return false;
        }


        bool insert(int index, int value) {
            if (index < 0 || index > length) {
                cout << "index out of bound";
                return false;
            }
            if (index == 0) {
                prepend(value);
                return true;
            }
            if (index == length) {
                append(value);
                return true;
            }
            Node* newNode = new Node(value);
            Node* before = get(index - 1);
            Node* after = before->next;
            newNode->prev = before;
            before->next = newNode;
            newNode->next = after;
            after->prev = newNode;
            length++;
            return true;
        }

        void deleteNode(int index) {
            if (index < 0 || index > length) {
                cout << "index out of bound";
                return;
            }
            Node* temp = get(index);
            if (index == 0) {
                deleteFirst();
            }
            if (index == length) {
                deleteLast();
            }
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
            length--;
        }

        void palindromeChecker() {
            Node* forward = head;
            Node* backward = tail;
            if (forward == nullptr) {
                cout << "empty";
                return;
            }
            while (forward) {
                if (forward->value == backward->value) {
                    forward = forward->next;
                    backward = backward->prev;
                } else {
                    cout << "Not Palindrome";
                    return;
                }
            }
            cout << "Palindrome";
        }

        void reverse() {
            if (head == nullptr) {
                cout << "empty";
                return;
            }
            Node* current = head;
            Node* temp = nullptr;
            while (current) {
                temp = current->prev;
                current->prev = current->next;
                current->next = temp;
                current = current->prev;
            }
            temp = head;
            head = tail;
            tail = temp;
        }

        void partitionList(int x) {
            if (head == nullptr) {
                cout << "empty";
                return;
            }

            Node* D1 = new Node(0);
            Node* D2 = new Node(0);

            Node* pre1 = D1;
            Node* pre2 = D2;

            Node* current = head;

            while (current) {
                Node* nextNode = current->next;
                current->next = nullptr;
                current->prev = nullptr;

                if (current->value < x) {
                    pre1->next = current;
                    current->prev = pre1;
                    pre1 = current;
                }else {
                    pre2->next = current;
                    current->prev = pre2;
                    pre2 = current;
                }
                current = nextNode;
            }

            pre1->next = D2->next;
            if (D2->next)
                D2->next->prev = pre1;

            head = D1->next ? D1->next : D2->next;
            if (head) head->prev = nullptr;
            delete D1;
            delete D2;
        }

        void reverseBetween(int m, int n) {
            if (!head || m == n) return;  // nothing to do

            Node* dummy = new Node(0);
            dummy->next = head;
            head->prev = dummy;  // link dummy backwards
            Node* prev = dummy;

            // Step 1: Move prev to the node just before position m
            for (int i = 0; i < m; i++) {
                prev = prev->next;
            }

            Node* start = prev->next;   // first node of sublist
            Node* then = start->next;   // node to be moved

            // Step 2: Reverse sublist
            for (int i = 0; i < n - m; i++) {
                start->next = then->next;             // detach 'then'
                if (then->next)
                    then->next->prev = start;        // fix backward link

                then->next = prev->next;             // move 'then' to front
                prev->next->prev = then;             // fix backward link
                prev->next = then;
                then->prev = prev;

                then = start->next;                   // move 'then' forward
            }

            // Step 3: Update head in case m == 0
            head = dummy->next;
            head->prev = nullptr;

            delete dummy;
        }

        void swapPairs() {
            if (!head || !head->next) return;

            Node* D = new Node(0);
            D->next = head;
            head->prev = D;

            Node* prev = D;

            while (prev->next && prev->next->next) {
                Node* first = prev->next;
                Node* second = first->next;

                // swap the two nodes
                prev->next = second;
                second->prev = prev;

                first->next = second->next;
                if (second->next)
                    second->next->prev = first;

                second->next = first;
                first->prev = second;

                // move prev to first (new position)
                prev = first;
            }

            head = D->next;
            head->prev = nullptr;

            delete D;
        }




};



int main() {
    DoublyLinkedList myDLL = DoublyLinkedList(1);

    myDLL.append(2);

    myDLL.append(3);

    myDLL.prepend(4);

    myDLL.set(4, 1);

    myDLL.insert(4, 4);

    myDLL.printList();

    int index;
    cout << "Choose an index to get the node from 0 to " << myDLL.getLength() <<  endl;
    cin >> index;
    cout << "Here is the node of the index " << index << " : "<< myDLL.get(index)->value << endl << endl << endl;


    cout << "Checking if there is a palindrome : " << endl;
    myDLL.palindromeChecker();
    cout << endl << endl;

    cout << "Reversing the list : " << endl;
    myDLL.reverse();
    myDLL.printList();
    cout << endl << endl;


    cout << "Before deleting last : " << endl;
    myDLL.printList();
    myDLL.deleteLast();
    cout << "After deleting last : " << endl;
    myDLL.printList();
    cout<< endl << endl;


    cout << "Before deleting first : " << endl;
    myDLL.printList();
    myDLL.deleteFirst();
    cout << "After deleting first : " << endl;
    myDLL.printList();


    cout << "Choose an index from 0 to " << myDLL.getLength() << " to delete its node " << endl;
    cin >> index;
    myDLL.deleteNode(index);
    cout << "After deleting node : " << endl;
    myDLL.printList();



    return 0;
}