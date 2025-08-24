#include <iostream>
using namespace std;
struct queue {
    int val;
    struct queue* next;
};

  void insertion(struct queue* &q,int num){
    struct queue* newq = (struct queue*)malloc(sizeof(struct queue));
    newq->val=num;
    newq->next = NULL;
    
    if(q == NULL){
        q = newq;
    } else{
        struct queue* temp=q;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newq;
    }
  }



 void display(struct queue* q){ 
      struct queue* temp=q;
     while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void deletion(struct queue* &q) {
    if (q == NULL) {
        cout << "Queue is empty, cannot deletion!" << endl;
        return;
    }

    q = (q)->next;

}
 

 int main(){
    struct queue *q = NULL;
    deletion(q);
    insertion(q,10);
    insertion(q,20);
    insertion(q,30);
    insertion(q,40);
    display(q);
    deletion(q); 
    display(q);
     }