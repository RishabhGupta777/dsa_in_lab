#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> m;
    pair<string, int> p1;
    p1.first = "raghav";
    p1.second = 76;
    m.insert(p1);

    m["Harsh"] = 15;
    m["Lokesh"] = 67;

    for (auto p : m) {
        cout << p.first << " " << p.second << endl;
    }
    cout<<endl;  
    m.erase("raghav");
    for (auto p : m) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
