#include <iostream>
#include <stack>
#include <string>


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

class Stack {
    private:
        Node* top;
        int height;
    public:
        Stack(int value) {
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }

        void printStack() {
            Node* temp = top;
            if (temp == nullptr) {
                cout << "Empty Stack" << endl;
            }
            else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        void getTop() {
            cout << "Top: " << top->value << endl;
        }

        void getHeight() {
            cout << "Height: " << height << endl;
        }

        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;

            height++;
        }

        // by void
        // void pop() {
        //     if (top == nullptr) {
        //         cout << "Empty Stack" << endl;
        //         return;
        //     }
        //     Node* temp = top;
        //     if (temp->next != nullptr) {
        //         top = temp->next;
        //         height--;
        //         delete temp;
        //     }
        // }

        // by int better bc it returns the popped value :(:):
        int pop() {
            if (height == 0) {
                cout << "Empty Stack" << endl;
                return INT_MIN ;
            }
            Node* temp = top;
            int poppedValue = top->value;
            top = top->next;
            delete temp;
            height--;
            return poppedValue;
        }
};
        string reverseString(const string& str) {
                    stack<char> st;
                    for (char ch : str) {
                        st.push(ch);
                    }
                    string result = "";
                    while (!st.empty()) {
                        result += st.top();
                        st.pop();
                    }
            return result;
        }

        bool isBalancedParentheses(const string& parentheses) {
            stack<char> st;
            for (int i = 0; i < parentheses.length(); i++) {
                if (parentheses[i] == '(') {
                    st.push('(');
                }
                else if (parentheses[i] == ')') {
                    if (st.empty()) {
                        cout << "Not Balanced" << endl;
                        return false;
                    }
                    st.pop();
                }
            }

            if (!st.empty()) {
                cout << "not balanced" << endl;
                return false;
            }
            if (st.empty()) {
                cout << "balanced" << endl;
                return true;
            }
        }

        void sortStack(stack<int>& inputStack) {
            stack<int> outputStack;
            while (!inputStack.empty()) {
                int temp = inputStack.top();
                inputStack.pop();
                while (!outputStack.empty() && outputStack.top() > temp) {
                    inputStack.push(outputStack.top());
                    outputStack.pop();
                }
                outputStack.push(temp);
            }
            while (!outputStack.empty()) {
                cout << outputStack.top() << "->";
                outputStack.pop();
            }
            cout << "NULL" << endl;
        }






int main() {
     // Stack mystack = Stack(5);
     // mystack.push(1);
     // mystack.push(2);
     // mystack.printStack();
     // mystack.getHeight();
     // mystack.getTop();
     // cout << endl;
     // cout <<"After popping" << endl;
     // cout << "Popped value is : " << mystack.pop()<< endl;
     // mystack.printStack();
     // mystack.getHeight();
     // mystack.getTop();
     // cout <<reverseString("amor");
     // cout << isBalancedParentheses("())")
     stack<int> inputStack;
     inputStack.push(1);
     inputStack.push(2);
     inputStack.push(6);
     inputStack.push(3);
     sortStack(inputStack);







    return 0;
}