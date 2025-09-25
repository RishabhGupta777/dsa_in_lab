#include <bits/stdc++.h>
using namespace std;

vector<int>dp;

int helper(vector<int> & arr,int target,int &count){
   
    if(target == 0) return count++;
    if(dp[target]!=-2) return dp[target];
    int result=INT_MAX;
    for(int i=0;i<arr.size();i++){
        if(target-arr[i]<0) break; //yha break islioye due 3-4 <0 hua to uske aage ka sab ke sab <0 hi hoga
        result = min(result,helper(arr,target-arr[i],count));
    }
}

int main(){
    dp.clear();
    vector<int> arr = {1,2,3,4,5,6};
    int target=3;
    int count=0;
    dp.resize(1000006,-2); 
    helper(arr,target,count);
    cout<<count;
}