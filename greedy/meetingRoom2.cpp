#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
       int ans=0;
       int room=0; //-->room=rooms are busy at present in meating
       vector<int>start;
       vector<int>end;
       for(auto arr:intervals){
        start.push_back(arr[0]);
        end.push_back(arr[1]);
       }
       sort(start.begin(),start.end());
       sort(end.begin(),end.end());
       int i=0,j=0;
       while(i<start.size()){
        if(start[i]<end[j]){
            i++;
            room++;
            ans=max(ans,room);
        }
        else if(start[i]>end[j]){
            j++;
            room--;
        }
        else{
            i++;
            j++;
        }
       }
       return ans;
    }
};

int main() {
    Solution s;
    // vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};  ans==2
   vector<vector<int>> intervals = {{2,15},{36,45},{9,29},{16,23},{4,9}};

    cout << s.minMeetingRooms(intervals) << endl;  // Output: 2
}
