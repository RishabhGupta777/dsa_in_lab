#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,string> prod;
    int n;
    cout<<"Enter the no. of production:";
    cin>>n;
    for(int i=0;i<n;i++){
         string leftSide;
        cout<<"Enter Left hand side of "<<i+1<<"th production:";
        cin>>leftSide;
        string rightSide;
        cout<<"Enter Right hand side of "<<i+1<<"th production:";
        cin>>rightSide;
        prod[leftSide]=rightSide;
    }

    for(auto x:prod){
        cout<<x.first<<"->"<<x.second<<endl;
        //find first teminal and not present after len travel the output Ephsilon
    string rhs = x.second;

    for(int i = 0; i < rhs.length()-1; i++) {

         if(rhs[i]=='e'){
           cout<<"It is not operator precedence Grammer";
           break; 
        }

        // if uppercase → non-terminal
        else if( isupper(rhs[i]) and  isupper(rhs[i+1]) ) {
           cout<<"It is not operator precedence Grammer";
           break;
        }
    }
    }
    
    
    
    

}
