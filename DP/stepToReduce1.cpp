#include <bits/stdc++.h>
using namespace std;

vector<int>dp;

int helper(int i){
   
    if(i==1) return 0;
    if(i==2 or i==3) return 1;
    if(dp[i]!=-1) return dp[i];
    return 1+ min({helper(i-1),(i%2==0) ? helper(i/2): INT_MAX ,(i%3==0) ? helper(i/3): INT_MAX });
}

int main(){
    dp.clear();
    int n=10;
    dp.resize(n+1,-1); 
    int ans=helper(n);
    cout<<ans;
}