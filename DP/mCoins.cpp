#include <bits/stdc++.h>
using namespace std;


int main(){
    int k,l,m;       //m-->no. of games b/w A and B
    cin>>k>>l>>m;
   
    vector<int>dp(1000005,0);

    //base cases
    dp[1]=1;
    dp[k]=1;
    dp[l]=1;
    for(int i=2;i<=1000000;i++){
        if(i==k or i==l) continue;
        dp[i]=!(dp[i-1] and ((i-k>=1) ? dp[i-k] : 1) and ((i-l>=1) ? dp[i-l] : 1));
    }
    for( int i=0;i<m;i++){  //m-->no. of games bw A and B 
        int n;
        cin>>n;  //height of m coins 
        if(dp[n]==1){
            cout<<"A";
        }
        else{
            cout<<"B";
        }
    }
}
