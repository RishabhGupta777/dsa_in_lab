#include <iostream>
#include <queue>
#include <vector>
using namespace std; 

int main() {
    int arr[] = {3, -4, -7, 30, 7, -9, 2, 1, 6, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    vector<int> ans;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(arr[i]<0) q.push(i);  //sare negative no. ka index store karana h queue me
    }
    int i=0;
    while(i<=n-k){ //loop to n-k tak hi chalana hoga naf
     while(q.size()>0 && q.front()<i) q.pop(); //q.front agar i se chota h matlab ki q.front koi kaam ka nahi h 
     //due to wo q.front purane window ka element hoga so ab wo koi kaam ka nahi h
     if(q.front()>i+k) ans.push_back(0);
     else ans.push_back(arr[q.front()]);
     i++;
    }
    for(int i=0;i<n;i++){
       cout<<arr[i]<<" " ;
    }
    for(int i=0;i<n;i++){
       cout<<ans[i]<<" " ;
    }

}