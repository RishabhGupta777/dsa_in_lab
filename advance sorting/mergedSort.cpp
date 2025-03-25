#include <iostream>
#include <vector>  
#include <string>  
#include <time.h>
#include<math.h>
#include <iomanip> // Include this for precision

using namespace std;

void merge(vector<int>&a,vector<int>&b,vector<int>&res){
int i=0,j=0,k=0;

while(i<a.size()&&j<b.size()){
    if(a[i]<b[j]){
       res[k]=a[i];
       k++;
       i++;
    }
    else{
       res[k]=b[j];
       k++;
       j++;
    }
}
if(i==a.size()){
    while(j<b.size()){
        res[k++]=a[j++];
    }
}
if(j==b.size()){
    while(i<a.size()){
        res[k++]=b[i++];
    }
}
}

void mergeSort( vector<int>&v){
int n=v.size();
if(n==1) return;
int n1=n/2 ,n2=n-n/2;
vector<int>a(n1),b(n2);
for (int i = 0; i < a.size();i++) {
       a[i]=v[i];
    }
for (int i = 0; i < b.size();i++) {
         b[i]=v[i+n1];
    }
mergeSort(a);
mergeSort(b);
merge(a,b,v);
}

double timemeasured(vector<int>&v){
    clock_t start,end;
    start=clock();
    mergeSort(v);
    end= clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC;

}

int main(){
    int arr[]={10,500,1000,10000,90000};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v(arr,arr+n);
    for (int i = 0; i < v.size();i++) {
        int m=v[i];
        vector<int> v(m);  //create a new vector each time
        for(int j=0; j<m; j++){
              v[j] = rand() % 100;
        }
        double time_taken;
        time_taken=timemeasured(v);
       cout << fixed << setprecision(5)<<"Time taken to sort "<<m<<" element:" << time_taken<<"seconds" << endl;

    }
    cout<<endl;
}