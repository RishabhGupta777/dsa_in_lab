#include<iostream>
#include <queue>
using namespace std;

int main(){
    int arr[]={6,5,3,2,8,10,9};
    int cost=0;
    priority_queue<int,vector<int>,greater<int>> pq;
        for(auto ele:arr){
            pq.push(ele);
        }
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            pq.push(x+y);
            cost+=(x+y);
        }
       cout<<cost;
}