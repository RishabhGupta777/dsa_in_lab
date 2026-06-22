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
    bool foundTerminal = false;

    for(int i = 0; i < rhs.length(); i++) {

        // if lowercase letter → terminal
        if(islower(rhs[i])) {
            cout << "First terminal: " << rhs[i] << endl;
            foundTerminal = true;
            break;
        }

        // if uppercase → non-terminal
        else if(isupper(rhs[i])) {
            cout << "Non-terminal " << rhs[i] << " found, need to check its production" << endl;
            foundTerminal = true;  // stop here for now (basic logic)
            break;
        }
    }

    if(!foundTerminal) {
        cout << "Epsilon (ε)" << endl;
    }

    cout << endl;
    }
    
    
    
    

}
