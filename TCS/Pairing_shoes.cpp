#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int,int> leftShoe;
    unordered_map<int,int> rightShoe;
    for(int i=0;i<n;i++) {
        string shoe;
        cin >> shoe;
        int size = stoi(shoe.substr(0, shoe.length()-1));
        char side = shoe.back();
        if(side == 'L')
            leftShoe[size]++;
        else
            rightShoe[size]++;
    }
    int pairs = 0;
    for(auto x : leftShoe) {
        int size = x.first;
        pairs += min(leftShoe[size], rightShoe[size]);
    }
    cout << pairs;

    return 0;
}