#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Node structure for Parse Tree
struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = right = NULL;
    }
};

// Function to check if character is operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to build parse tree from postfix expression
Node* buildParseTree(string postfix) {
    stack<Node*> st;

    for (char ch : postfix) {
        // If operand, push to stack
        if (isalnum(ch)) {
            st.push(new Node(ch));
        }
        // If operator, pop two nodes
        else if (isOperator(ch)) {
            Node* right = st.top(); st.pop();
            Node* left = st.top(); st.pop();

            Node* newNode = new Node(ch);
            newNode->left = left;
            newNode->right = right;

            st.push(newNode);
        }
    }

    return st.top();
}

// Inorder traversal (to display tree)
void inorder(Node* root) {
    if (root) {
        if (isOperator(root->data)) cout << "(";
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
        if (isOperator(root->data)) cout << ")";
    }
}

// Preorder traversal
void preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal
void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    Node* root = buildParseTree(postfix);

    cout << "\nInorder (Infix): ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}