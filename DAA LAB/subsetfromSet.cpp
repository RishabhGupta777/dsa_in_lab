#include <iostream>
#include <vector>
using namespace std;

void helper(vector<int>& nums, vector<int> ans, vector<vector<int>>& finalAns, int idx) {
    if (idx == nums.size()) {
        finalAns.push_back(ans);
        return;
    }

    // Not take current element
    helper(nums, ans, finalAns, idx + 1);

    // Take current element
    ans.push_back(nums[idx]);
    helper(nums, ans, finalAns, idx + 1);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> ans;
    vector<vector<int>> finalAns;
    helper(nums, ans, finalAns, 0);
    return finalAns;
}

int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> allSubsets = subsets(nums);

    cout << "All subsets:\n";
    for (const auto& subset : allSubsets) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;
}
