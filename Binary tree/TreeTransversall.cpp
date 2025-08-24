#include<iostream>
using namespace std;

struct Node{
    int val;
    struct Node* left;
    struct Node* right;

};

int size(Node* root){
    if(root==NULL) return 0;
    return 1 + size(root->left) + size(root->right);
  }

void preorder(Node* root){
    if(root==NULL) return ;
    cout<<root->val<<" ";  // work
    preorder(root->left); //call 1
    preorder(root->right); //call 2
}

void inorder(Node* root){
    if(root==NULL) return ;
   
    inorder(root->left); //call 1
    cout<<root->val<<" ";  // work
    inorder(root->right); //call 2
}

void postorder(Node* root){
    if(root==NULL) return ;
    
    postorder(root->left); //call 1
    postorder(root->right); //call 2
    cout<<root->val<<" ";  // work
}


int main(){

    // Create nodes using new
    struct Node* a = new Node{1, nullptr, nullptr};
    struct Node* b = new Node{2, nullptr, nullptr};
    struct Node* c = new Node{3, nullptr, nullptr};
    struct Node* d = new Node{4, nullptr, nullptr};
    struct Node* e = new Node{5, nullptr, nullptr};
    struct Node* f = new Node{6, nullptr, nullptr};
    struct Node* g = new Node{7, nullptr, nullptr};

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;

  cout<<"size of BT is:"<<size(a)<<endl;
  preorder(a);    cout<<endl;
  inorder(a);     cout<<endl;
  postorder(a);

  
}