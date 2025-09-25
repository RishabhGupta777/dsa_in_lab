#include <bits/stdc++.h>
using namespace std;

vector<int>dp;

int helper(int i){
   
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];
    int a=i%10;
    int b=i/10;
    return dp[i]=1+helper(i-max(a,b));
}

int main(){
    dp.clear();
    int n=101;
    dp.resize(n+1,-1); 
    int ans=helper(n);
    cout<<ans;
}