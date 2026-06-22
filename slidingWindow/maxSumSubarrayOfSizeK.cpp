#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={7,1,2,5,8,4,9,3,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int prevSum=0;
    for(int i=0;i<k;i++){
        prevSum += arr[i];
    }
    int maxSum=prevSum;
    int maxIdx=0;
    int i=1,j=k;
    while(j<n){
       int currSum=prevSum+ arr[j]-arr[i-1];
        if(maxSum<currSum){
            maxIdx=i;
            maxSum=currSum;
        }
        prevSum=currSum;
        i++;
        j++;
    }
    cout<<maxSum<<"\n";
    cout<<maxIdx;

}