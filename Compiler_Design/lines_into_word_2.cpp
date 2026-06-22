#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    getline(cin,line);
    vector<string> answer;
    string word="";
    
    for(int i=0;i<line.length();i++){
            if(line[i]!=' '){
           word +=line[i];
        }
        else{ //jaise hi kahli space dikh  jae '  '
           if (!word.empty()) {
                answer.push_back(word);
                word = "";
            }
        }
        }
        //for printing the last line
        if (!word.empty()) {
                answer.push_back(word);
        }
        
        cout<<"no. of words:"<< answer.size()<<'\n';
     for (int i = 0; i < answer.size(); i++) {
    cout << answer[i] << endl;
    }

}

// if we use the this from loop and char intead of string and not use vector only print

// int main() {
    
//      string word="";
    
    
//     char line[100];
//     cin.getline(line, 100);
//     for (char ch : line) {
//         if (ch == '\0') break;
//         if(ch!=' '){
//            word +=ch;
//         }
//         else{ //jaise hi kahli space dikh  jae '  '
//            if (!word.empty()) {
//                 cout << word << endl;
//                 word = "";
//             }
//         }
//         }
//         //for printing the last line
//         if (!word.empty()) {
//                 cout << word << endl;
//         }
     
// } 

