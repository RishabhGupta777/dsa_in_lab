#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int minumumCost(vector<int> &X,vector<int> &Y){
  int cost=0;
  int hz=1; //no. of horizontal blocks initially
  int vz=1;// number of vertical segments
  int h=0,v=0;
  sort(X.begin(),X.end(),cmp);
  sort(Y.begin(),Y.end(),cmp);
  while(h<Y.size() && v<X.size()){
    if(X[v]>Y[h]){ //vertical cut laga rhe
      cost+=X[v]*hz;  //If you do a vertical cut, you must multiply its cost by current hz (number of horizontal segments).
      vz++;  //vertical cuts inc vertical blocks/segements
      v++; //pointer of X which is v inc;
    }
    else{  //horizotal cut
      cost+=Y[h]*vz;//If you do a horizontal cut, you must multiply its cost by current vz (number of vertical segments).
      hz++;
      h++;
    }
  }
  // Remaining horizontal cuts
  while(h<Y.size()){
      cost+=Y[h]*vz;
      hz++;
      h++;
  }
  // Remaining vertical cuts
  while( v<X.size()){
   cost+=X[v]*hz;
      vz++;  //vertical cuts inc horzoinatal blocks
      v++; //pointer of X which is v inc;
  }
  return cost;
}
int main(){
   vector<int>X{2,1,3,1,4}; //X=horizontal cuts can be done
   vector<int>Y{4,1,2};  // horizontal cuts
   int product = minumumCost(X,Y);
   cout<<product;
}