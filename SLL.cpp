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

class SingleLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;
    public:
        SingleLinkedList(int value)
        {
            Node* newnode = new Node (value) ;
            head = newnode;
            tail = newnode;
            length = 1 ;
        }

        ~SingleLinkedList() {
            Node* temp = head;
            while (head) {
                temp = head;
                head = head->next;
                delete temp;
            }
        }

        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        void append(int value) {
            Node* newnode = new Node(value);
            if (head == nullptr) {
            head = newnode;
            tail = newnode;
            newnode->next = nullptr;
            }
            else {
                tail->next = newnode;
                tail = newnode;
            }
            length++;
        }
                    // No tail append
        // void app(int value) {
        //     Node* newnode = new Node(value);
        //     if (head == nullptr) {
        //         head = newnode;
        //         newnode->next = nullptr;
        //     }
        //     else {
        //         Node* temp = head;
        //         while (temp->next) {
        //             temp = temp->next;
        //         }
        //         temp->next = newnode;
        //         newnode->next = nullptr;
        //     }
        // }

        void DeleteLast() {
                if (length == 0)return;
                Node* temp = head;
                if (length == 1) {
                    head = nullptr;
                    tail = nullptr;
                }
                else {
                    Node* pre = head;
                    while (temp->next) {
                        pre = temp;
                        temp = temp->next;
                    }
                    tail = pre;
                    tail->next = nullptr;
                }
                delete temp;
                length--;
        }
                    // No tail delete last
        // void Deletelast() {
        //     if (length == 0)return;
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
        // }

        void prepend(int value) {
                Node* newnode = new Node(value);
                if (length == 0) {
                    head = newnode;
                    tail = newnode;
                }
                else {
                    newnode->next = head;
                    head=newnode;
                }
                length++;
        }

        void DeleteFirst() {
                if (length == 0)return;
                Node* temp = head;
                if (length == 1) {
                    head = nullptr;
                    tail = nullptr;
                }
                else {
                    head = temp->next;
                }
                delete temp;
                length--;
        }

        Node* get(int index) {
            if (index < 0 || index >= length) {
                return nullptr;
            }
            Node* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp;
        }

        bool set(int index , int value) {
            Node* temp = get(index);
            if (temp) {
                temp->value = value;
                return true;
            }
            return false;
        }

        int Search(int value) {
            Node* temp = head;
            int index;
            for (int i = 0; i < length; i++) {
                if (temp->value == value) {
                    index = i;
                }
                temp = temp->next;
            }
            return index;
        }

        bool insert(int index, int value) {
            if (index < 0 || index > length) {
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
            Node* temp = get(index-1);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
            return true;
        }

        void deleteNode(int index) {
            if (index < 0 || index >= length) {
                return;
            }
            if (index == 0) {
                return DeleteFirst();
            }
            if (index == length - 1) {
                return DeleteLast();
            }
            Node* prev = get(index - 1);
            Node* temp = prev->next;
            prev->next = temp->next;
            delete temp;
            length--;
        }

        void reverse() {
            Node* temp = head;
            head = tail;
            tail = temp;

            Node* before = nullptr;

            for (int i = 0 ; i <length; i++) {
                Node* after = temp->next;
                temp->next = before;
                before = temp;
                temp = after;
            }
        }


        Node* findMiddleNode() {
            Node* fast= head;
            Node* slow= head;

            while (fast ) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }

        bool hasloop () {
            Node* fast = head;
            Node* slow = head;
            while (fast && fast->next) {
                fast = fast->next->next;
                slow = slow->next;
                if (fast == slow) {
                    return true;
                }
            }
            return false;
        }

        Node * findKthFromEnd(int k) {
            if (k<=0)return nullptr;
            Node* fast = head;
            Node* slow = head;
            for (int i = 0 ; i < k ; i++) {
                if (fast == nullptr)return nullptr;
                fast = fast->next;
            }
            while (fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }

        void removeDuplicates() {
            Node* current = head;
            while (current) {
                Node* runner = current;
                while (runner->next) {
                   if (runner->next->value == current->value) {
                    Node* temp = runner->next;
                    runner->next = runner->next->next;
                    delete temp;
                    length--;
                    }
                    else {
                        runner = runner->next;
                    }
                }
                current = current->next;
            }
        }

        int binaryToDecimal() {
            Node* current = head;
            int num = 0;
            while (current) {
                num = num * 2 + current->value;
                current = current->next;
            }
            return num;
        }

        // void partitionList(int x) {
        //     if (head == nullptr) {
        //         return;
        //     }
        //     Node* D1 = new Node(0);
        //     Node* D2 = new Node(0);
        //     Node* pre1 = D1;
        //     Node* pre2 = D2;
        //     Node* temp = head;
        //     while (temp) {
        //         if ( temp->value >= x) {
        //             D2->next = temp;
        //             pre2 = pre2->next;
        //         }
        //         else {
        //            D1->next = temp;
        //            pre1 = pre1->next;
        //         }
        //         temp = temp->next;
        //     }
        //     pre1 = D2->next;
        //     delete D2;
        //     delete pre1;
        //     delete pre2;
        //     head = D1->next ;
        //     delete D1;
        // }

        void partitionList(int x) {

            // If list empty → nothing to do
            if (head == nullptr) return;

            // Dummy nodes for two lists
            Node* D1 = new Node(0);
            Node* D2 = new Node(0);

            Node* pre1 = D1;
            Node* pre2 = D2;

            Node* current = head;

            while (current) {
                if (current->value < x) {
                    pre1->next = current;
                    pre1 = current;
                } else {
                    pre2->next = current;
                    pre2 = current;
                }
                current = current->next;
            }

            // End the greater list
            pre2->next = nullptr;

            // Connect the two lists
            pre1->next = D2->next;

            // Update head
            head = D1->next;

            // Free dummy nodes
            delete D1;
            delete D2;
        }

        void reverseBetween(int m, int n) {
            if (!head || m == n) return;  // nothing to do

            // Create a dummy node to simplify head manipulations
            Node* dummy = new Node(0);
            dummy->next = head;
            Node* prev = dummy;

            // Step 1: Move prev to the node just before position m
            for (int i = 0; i < m; i++) {
                prev = prev->next;
            }

            // Step 2: Initialize start and then pointers
            Node* start = prev->next;    // first node of the sublist to reverse
            Node* then = start->next;    // node that will be moved

            // Step 3: Reverse the sublist from m to n
            for (int i = 0; i < n - m; i++) {
                start->next = then->next;   // detach 'then' from sublist
                then->next = prev->next;    // move 'then' to the front of reversed part
                prev->next = then;          // connect prev to 'then'
                then = start->next;         // move 'then' forward
            }

            // Step 4: Update head in case m = 0
            head = dummy->next;
            delete dummy;  // clean up
        }


        // void swapPairs() {
        //     if (head == nullptr) return;
        //     Node*D=new Node(0);
        //     D->next = head;
        //     Node* prev = D;
        //     Node* first = D->next;
        //     Node* second = first->next;
        //     while (first && first->next) {
        //         first->next = second->next;
        //         second->next = D->next;
        //         prev = first;
        //         first = first->next;
        //         second = first->next;
        //     }
        //     first = nullptr;
        //     second = nullptr;
        //     prev = nullptr;
        //     delete first;
        //     delete second;
        //     delete prev;
        //     head = D->next;
        // }


    void swapPairs() {
            if (!head || !head->next) return;

            Node* D = new Node(0);
            D->next = head;

            Node* prev = D;

            while (prev->next && prev->next->next) {
                Node* first = prev->next;
                Node* second = first->next;

                prev->next = second;
                first->next = second->next;
                second->next = first;

                prev = first;
            }

            head = D->next;
            delete D;
        }



};



int main() {
    SingleLinkedList* myLinkedList = new SingleLinkedList(4);
    myLinkedList->append(3);
    myLinkedList->prepend(6);
    myLinkedList->append(2);
    myLinkedList->prepend(7);
    myLinkedList->insert(2,5);
    myLinkedList->append(4);
    myLinkedList->prepend(2);
    // myLinkedList->append(1);
    // myLinkedList->append(0);
    // myLinkedList->append(1);
    // myLinkedList->append(1);

    int value;
    cout << "Type a value that you want to search its index: "  << endl;
    cin >> value;
    cout << myLinkedList->Search(value);






    // cout << "Type an index that you want to get its value from the LL" << endl;
    // cin>>index;
    //
    // cout << myLinkedList->get(index)->value << endl;
    //
    cout << "\nLinked List:\n";
    myLinkedList->printList();
    //
    //
    // myLinkedList->reverse();
    // cout << "LinkedList after reverse " <<endl;
    // myLinkedList->printList();
    //
    // cout << " The middle node is " << myLinkedList->findMiddleNode()->value<<endl;
    //
    // cout << " Checking if the LL has loop: " << myLinkedList->hasloop() << endl;
    //
    // int k;
    // cout << " Type a number to find the node from the end : " << endl;
    // cin >> k;
    // cout << " THE Kth node is " << myLinkedList->findKthFromEnd(k)->value<<endl;
    //
    // cout << " Checking if there are duplicates and removing them : " << endl;
    // myLinkedList->removeDuplicates();
    // cout<<" Linked list after checking : " << endl;
    // myLinkedList->printList();
    //
    // cout << " The binary values in decimal are : " << endl;
    // cout << myLinkedList->binaryToDecimal() << endl;
    //
    // int x;
    // cout << " Enter a number for partitioning : " << endl;
    // cin >> x ;
    // cout << " Partitioning the list : " << endl;
    // myLinkedList->partitionList(x);
    // myLinkedList->printList();







    // myLinkedList->DeleteLast();
    // cout << "\nAfter first delete last Linked List:\n";
    // myLinkedList->printList();
    //
    // cout << "Before delete first Linked List:\n";
    // myLinkedList->printList();
    //
    // myLinkedList->DeleteFirst();
    // cout << "After first delete first Linked List:\n";
    // myLinkedList->printList();
    //
    // myLinkedList->DeleteLast();
    // cout << "\nAfter second delete last Linked List:\n";
    // myLinkedList->printList();
    //
    // myLinkedList->DeleteFirst();
    // cout << "\nAfter second delete first Linked List:\n";
    // myLinkedList->printList();

    // myLinkedList->DeleteLast();
    // cout << "\n After third delete last Linked List:\n";
    // myLinkedList->printList();
    //
    // myLinkedList->DeleteFirst();
    // cout << "\n After third delete first Linked List:\n";
    // myLinkedList->printList();





    return 0;

}