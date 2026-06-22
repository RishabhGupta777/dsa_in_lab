#include<bits/stdc++.h>
using namespace std;

 void findleading(map<string,string>& prod,string s){
    string rhs=prod[s];
    bool foundTerminal = false;

    for(int i = rhs.length()-1; i >=0 ; i--) {
        // if lowercase letter → terminal
        if(islower(rhs[i])) {
            cout << "Trailing terminal: " << rhs[i] << endl;
            foundTerminal = true;
            break;
        }

        // if uppercase → non-terminal
        else if(isupper(rhs[i])) {
            string newRHS(1, rhs[i]);   // convert char → string
            findleading(prod,newRHS);
            foundTerminal = true;  // stop here for now (basic logic)
            break;
        }
    }

    if(!foundTerminal) {
        cout << "Ephsilon";
    }

    cout << endl;

}
    
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
        findleading(prod, x.first);
        cout<<endl;
    }
    
    
    
    

}
