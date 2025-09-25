#include <bits/stdc++.h>
using namespace std;

vector<int>dp;

int helper(vector<int> & arr,int target){
   
    if(target == 0) return 0;
    if(dp[target]!=-2) return dp[target];
    int result=INT_MAX;
    for(int i=0;i<arr.size();i++){
        if(target-arr[i]<0) continue;  //test case for this line [1,5,11,20] but target is 11
        result = min(result,helper(arr,target-arr[i]));
    }
    if(result==INT_MAX) return dp[target]=INT_MAX;
    return 1+result;
}

int main(){
    dp.clear();
    vector<int> arr = {3, 5, 7};//-->jab sum ho hi na sab skip ho jaye then give -1 answer
    int target=2;
    dp.resize(1000006,-2); 
    int ans=helper(arr,target);
    if(ans==INT_MAX)cout<<-1;
    else cout<<ans;
}