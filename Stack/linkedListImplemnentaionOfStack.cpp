#include <iostream>
using namespace std;
struct stack {
    int val;
    struct stack* next;
};

  void push(struct stack* &stack,int num){
    struct stack* new_s = (struct stack*)malloc(sizeof(struct stack));
      new_s->val=num;

    new_s->next = stack; // Set new_s->next to current stack
    stack = new_s; // Update stack to new_s

    }
  
void display(struct stack* stack){ 
      struct stack* temp=stack;
     while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void pop(struct stack* &stack) {
    if (stack == NULL) {
        cout << "stack is empty, cannot pop!" << endl;
        return;
    }

    stack = stack->next;

}
 

 int main(){
    struct stack *stack = NULL;
    pop(stack); 
    push(stack,10);
    push(stack,20);
    push(stack,30);
    push(stack,40);
    display(stack);
    pop(stack); 
    display(stack);
     }