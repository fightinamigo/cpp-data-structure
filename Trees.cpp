#include <iostream>
#include <queue>
using namespace std;

// ============================================================
//  BINARY SEARCH TREE — Complete Implementation
//  Operations:
//   1. insert                — iterative, duplicates go left
//   2. rInsert               — recursive insertion
//   3. contains              — iterative search (true/false)
//   4. rContains             — recursive search (true/false)
//   5. BFS                   — level-by-level traversal (Queue)
//   6. inOrder               — Left → Root → Right (sorted)
//   7. preOrder              — Root → Left → Right
//   8. postOrder             — Left → Right → Root
//   9. deleteNode            — handles all 3 cases (recursive)
//   10. search               — find/print all nodes with exact value
//   11. displayLessOrEqual    — all nodes with value <= limit
//   12. displayGreaterOrEqual — all nodes with value >= limit
// ============================================================


// ── NODE ────────────────────────────────────────────────────

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        left  = nullptr;
        right = nullptr;
    }
};


// ── BST ─────────────────────────────────────────────────────

class BST {
private:
    void destroyTree(Node* node) {
        if (node == nullptr) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    Node* root;

    BST() {
        root = nullptr;
    }

    ~BST() {
        destroyTree(root);
    }

    // ── 1. INSERT (iterative) ──────────────────────────────
    // Equal values go LEFT
    bool insert(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            return true;
        }
        Node* temp = root;
        while (true) {
            if (newNode->value <= temp->value) {
                if (temp->left == nullptr) { temp->left = newNode; return true; }
                temp = temp->left;
            } else {
                if (temp->right == nullptr) { temp->right = newNode; return true; }
                temp = temp->right;
            }
        }
    }

    // ── 2. INSERT (Recursive) ──────────────────────────────
    // Equal values go LEFT
    Node* rInsert(Node* currentNode, int value) {
        if (currentNode == nullptr) return new Node(value);

        if (value <= currentNode->value) {
            currentNode->left = rInsert(currentNode->left, value);
        } else {
            currentNode->right = rInsert(currentNode->right, value);
        }
        return currentNode;
    }
    void rInsert(int value) {
        root = rInsert(root, value);
    }

    // ── 3. CONTAINS (iterative) ────────────────────────────
    // Returns true if value exists, false otherwise
    bool contains(int value) {
        if (root == nullptr) return false;
        Node* temp = root;
        while (temp) {
            if (value < temp->value)      temp = temp->left;
            else if (value > temp->value) temp = temp->right;
            else {
                cout << "Found: " << temp->value << endl;
                return true;
            }
        }
        cout << "Not found" << endl;
        return false;
    }

    // ── 4. CONTAINS (Recursive) ────────────────────────────
    // Returns true if value exists, false otherwise
    bool rContains(Node* currentNode, int value) {
        if (currentNode == nullptr) return false;
        if (currentNode->value == value) return true;
        if (currentNode->value > value) {
            return rContains(currentNode->left, value);
        }
        return rContains(currentNode->right, value);
    }
    bool rContains(int value) {
        return rContains(root, value);
    }


    // — 5. Breadth First Search:
    // Result: level-by-level order (top to bottom, left to right)
    void BFS() {
        if (root == nullptr) return;
        queue<Node*> myQueue;
        myQueue.push(root);

        while (myQueue.size() > 0) {
            Node* currentNode = myQueue.front();
            myQueue.pop();
            cout << currentNode->value << " ";
            if (currentNode->left) {
                myQueue.push(currentNode->left);
            }
            if (currentNode->right) {
                myQueue.push(currentNode->right);
            }
        }
        cout << endl;
    }

    // ── 6. IN-ORDER: Left → Root → Right ──────────────────
    // Result: ascending sorted order
    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->value << " ";
        inOrder(node->right);
    }
    void inOrder() { inOrder(root); cout << endl; }

    // ── 7. PRE-ORDER: Root → Left → Right ─────────────────
    // Result: useful for copying the tree
    void preOrder(Node* node) {
        if (node == nullptr) return;
        cout << node->value << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
    void preOrder() { preOrder(root); cout << endl; }

    // ── 8. POST-ORDER: Left → Right → Root ────────────────
    // Result: useful for deleting the tree
    void postOrder(Node* node) {
        if (node == nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->value << " ";
    }
    void postOrder() { postOrder(root); cout << endl; }

    // ── 9. DELETE NODE (recursive) ────────────────────────
    // Case 1: leaf node     → just remove
    // Case 2: one child     → link parent directly to that child
    // Case 3: two children  → replace with in-order successor
    //                         (smallest node in right subtree)
    Node* minNode(Node* node) {
        while (node->left)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) return nullptr;

        if (value < node->value) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->value) {
            node->right = deleteNode(node->right, value);
        } else {
            // CASE 1: leaf
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // CASE 2a: only right child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            // CASE 2b: only left child
            if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // CASE 3: two children → replace with in-order successor
            Node* successor = minNode(node->right);
            node->value = successor->value;
            node->right = deleteNode(node->right, successor->value);
        }
        return node;
    }
    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    // ── 10. SEARCH: find all nodes with exact value ─────────
    // Uses inOrder traversal — continues left after a match
    // because duplicates are stored on the left
    void search(Node* node, int value) {
        if (node == nullptr) return;
        search(node->left, value);
        if (node->value == value)
            cout << "Found: " << node->value << endl;
        if (node->value < value)
            search(node->right, value);
    }
    void search(int value) {
        cout << "Searching for " << value << ":" << endl;
        search(root, value);
    }

    // ── 11. DISPLAY LESS OR EQUAL: value <= limit ───────────
    // Prints all nodes with value <= limit in sorted order
    // Skips right subtree early once current node exceeds limit
    void displayLessOrEqual(Node* node, int limit) {
        if (node == nullptr) return;
        displayLessOrEqual(node->left, limit);
        if (node->value <= limit)
            cout << node->value << " ";
        if (node->value < limit)
            displayLessOrEqual(node->right, limit);
    }
    void displayLessOrEqual(int limit) {
        cout << "Values <= " << limit << ": ";
        displayLessOrEqual(root, limit);
        cout << endl;
    }

    // ── 12. DISPLAY GREATER OR EQUAL: value >= limit ────────
    // Prints all nodes with value >= limit in sorted order
    // Skips left subtree early once current node is below limit
    void displayGreaterOrEqual(Node* node, int limit) {
        if (node == nullptr) return;
        if (node->value > limit)
            displayGreaterOrEqual(node->left, limit);
        if (node->value >= limit)
            cout << node->value << " ";
        displayGreaterOrEqual(node->right, limit);
    }
    void displayGreaterOrEqual(int limit) {
        cout << "Values >= " << limit << ": ";
        displayGreaterOrEqual(root, limit);
        cout << endl;
    }
};


// ── MAIN ─────────────────────────────────────────────────────

int main() {
    BST* myBST = new BST();

    // myBST->insert(47);
    // myBST->insert(20);
    // myBST->insert(70);
    // myBST->insert(17);
    // myBST->insert(52);
    // myBST->insert(82);
    // myBST->insert(27);
    // myBST->insert(20); // duplicate → goes left
    myBST->rInsert(47);
    myBST->rInsert(20);
    myBST->rInsert(70);
    myBST->rInsert(17);
    myBST->rInsert(52);
    myBST->rInsert(82);
    myBST->rInsert(27);
    myBST->rInsert(20); // duplicate → goes left

    // ── Traversals ──
    cout << "=== Traversals ===" << endl;
    cout << "In-Order   (sorted): "; myBST->inOrder();    // 17 20 20 27 47 52 70 82
    cout << "Pre-Order           : "; myBST->preOrder();   // 47 20 17 20 27 70 52 82
    cout << "Post-Order          : "; myBST->postOrder();  // 17 20 27 20 52 82 70 47

    // ── Contains ──
    cout << "\n=== Contains ===" << endl;
    myBST->contains(20);  // Found
    myBST->contains(99);  // Not found

    // ── Recursive Contains ──
    cout << "\n=== Recursive Contains ===" << endl;
    cout << myBST->rContains(20); // Found
    cout << myBST->rContains(99); // Not found

    // ── Search ──
    cout << "\n=== Search ===" << endl;
    myBST->search(20);    // finds both 20s

    // ── BFS ──
    cout << "\n=== BFS ===" << endl;
    myBST->BFS();

    // ── Range queries ──
    cout << "\n=== Range Queries ===" << endl;
    myBST->displayLessOrEqual(47);    // 17 20 20 27 47
    myBST->displayGreaterOrEqual(47); // 47 52 70 82

    // ── Delete ──
    cout << "\n=== Delete ===" << endl;
    cout << "Before: "; myBST->inOrder();
    myBST->deleteNode(20);  // Case 3: two children
    cout << "After deleting 20: "; myBST->inOrder();
    myBST->deleteNode(82);  // Case 1: leaf
    cout << "After deleting 82: "; myBST->inOrder();
    myBST->deleteNode(70);  // Case 2: one child
    cout << "After deleting 70: "; myBST->inOrder();

    delete myBST;
    return 0;
}