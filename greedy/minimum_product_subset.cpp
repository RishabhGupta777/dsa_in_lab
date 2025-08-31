#include<iostream>
#include <algorithm>
#include <climits>
#include<vector>
using namespace std;
int minimumProduct(vector<int> &arr){
    //cn=count of negative no. ; cz=no. of zeroes ; cp=no. of positive no.
    int cn=0,cz=0,cp=0;
    int prodNeg=1,prodPos=1;
    int largestNeg=INT_MIN;
      for(int i=0;i<arr.size();i++){
         if(arr[i]<0) {
            cn++;
           prodNeg *= arr[i];
         largestNeg=max(largestNeg,arr[i]);
        }
         if(arr[i]==0) cz++;
         if(arr[i]>0) {
            cp++;
           prodPos *= arr[i];
        } 
      }
   
    if(cn==0 && cz>0) return 0;
    if(cn==0 && cz==0){
      auto it=min_element(arr.begin(),arr.end());
      return *it;
    }
    if(cn>0 && cn%2==0){  //even negative ho ta
        return (prodNeg/largestNeg)*prodPos;
    } 
    if(cn>0 && cn%2!=0 ){
        return prodNeg*prodPos;
    }
}
int main(){
   vector<int>arr{-2,-3,1,4,-2};
   int product = minimumProduct(arr);
   cout<<product;
    
}