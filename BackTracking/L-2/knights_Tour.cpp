#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> &grid,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<' ';
        }
        cout<<'\n';
    }
}

bool isSafe(vector<vector<int>> &grid,int r,int c,int n){
    return r>=0 and c>=0 and r<n and r<n and grid[r][c]==-1;
}
vector<int>dx={-2,-1,-2,-1,+1,+2,+1,+2};
vector<int>dy={+1,+2,-1,-2,-2,-1,+2,+1};
void knight(vector<vector<int>> &grid,int i,int j,int n,int count){
   if(count==n*n-1){ //->menas tum last position pe ho to
    grid[i][j]=count; //wha count ko fit kar do
    display(grid,n);
    cout<<"****\n"; //display hone ke baad dikado ki ek path kahatam ho gya
    grid[i][j]=-1;  //phir uss postion ko -1 pe set kar do taki baki new path mil paye
    return;
   }
   for(int k=0;k<8;k++){ //8=for 8 direction
   if(isSafe(grid,i+dx[k],j+dy[k],n)){
    grid[i][j]=count;
    knight(grid,i+dx[k],j+dy[k],n,count+1);
    grid[i][j]=-1;
   }
   }
   
}
int main(){
    int n=5;
    cout<<n;
    vector<vector<int>> grid(n,vector<int>(n,-1));
     knight(grid,0,0,n,0);
}