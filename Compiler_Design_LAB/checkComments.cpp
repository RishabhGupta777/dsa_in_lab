#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin, s);

    int n = s.length();

    if(n>=2 and (
        (s[0]=='/' and s[1]=='/') 
                    or
        (s[0]=='/' and s[1]=='*' and s[n-2]=='*' and s[n-1]=='/')
                )){
                    cout<<"this is a comment";
                }
    else{
        cout<<"This is not a comment";
    }
} 