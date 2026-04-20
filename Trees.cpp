#include <iostream>

using namespace std;


class Node {
    public:
        int value ;
        Node* left;
        Node* right;

    Node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};


class BST {
    public:
        Node* root;
        BST() {
            root = nullptr;
        }
        bool insert(const int value) {
            Node* newNode = new Node(value);
            if (root == nullptr) {
                root = newNode;
                return true;
            }
            Node* temp = root;
            while (true) {
                if (newNode->value == temp->value) {
                    cout << "value already exists " << endl;
                    return false;
                }
                if ( newNode->value < temp->value ) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                }else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }


        bool contains( int value) {
            if (root == nullptr) {
                return false;
            }
            Node* temp = root;
            while (temp) {
               if (temp->value > value) {
                   temp = temp->left;
               }
               else if (temp->value < value) {
                    temp = temp->right;
               }
               else {
                   cout << "Found value "<< temp->value << endl;
                   return true;
               }
            }
            cout << "Not found" << endl;
            return false;
        }
};

int main() {
    BST* myBST = new BST() ;


    myBST->insert(47);
    myBST->insert(20);
    myBST->insert(70);
    myBST->insert(17);
    myBST->insert(52);
    myBST->insert(82);
    myBST->insert(27);

    int x;
    cout << "Please enter an integer to search for in the tree: " << endl;
    cin >> x;
    cout << "Searching for the value in the tree: " << endl;
    cout << myBST->contains(x)<< endl;

    cout << endl;




    return 0;
}
