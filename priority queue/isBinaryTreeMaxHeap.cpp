#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
    int val;
    Node *left;
    Node *right;
    Node(int val){
        this->val=val;
         this->left = NULL;  //<--isko must intialize nahi to code hi nahi chalega
        this->right = NULL;
    }
};
int sizeOfTree(Node* root){
if(root==NULL) return 0;
return 1+sizeOfTree(root->left)+sizeOfTree(root->right);
}
 bool isCBT(Node* root){
    int size=sizeOfTree(root);
    int count;
        queue<Node*>q;
        q.push(root);
        while(count<size){
            Node* temp=q.front();
            q.pop();
            count++;
            if(temp!=NULL){
                q.push(temp->left);
                q.push(temp->left);
            }
        }
        while(q.size()>0){
            if(q.front()==NULL) return false;
            q.pop();
        }
    }

bool isMax(Node * root){
  if(root==NULL) return true;
  if(root->left!=NULL && root->val<root->left->val) return false;
  if(root->right!=NULL && root->val<root->right->val) return false;
  return isMax(root->left) && isMax(root->right);
}
int main(){
    Node* a = new Node(10);
    Node* b = new Node(5);
    Node* c = new Node(16);
    Node* d = new Node(1);
    Node* e = new Node(8);
    Node* f = new Node(12);
    Node* g = new Node(20);

    a->left = b;  a->right = c;
    b->left = d;  b->right = e;
    c->left = f;  c->right = g;
    if(isCBT(a) && isMax(a)) cout<<"Tree is MaxHeap";
    else cout<<"Tree is NOT MaxHeap";
}