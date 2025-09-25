#include <bits/stdc++.h>
using namespace std;

double getMedian(priority_queue<int> &left,
                 priority_queue<int, vector<int>, greater<int>> &right,
                 int x, int y) {
    int totalSize = x + y;
    if (totalSize % 2 != 0) {
        return right.top();
    } else {
        return (left.top() + right.top()) / 2.0;
    }
}

bool isBalanced(int x, int y) {
    return (x == y) or (x + 1 == y);
}

vector<double> sliding_median(vector<int> &arr, int n, int k) {
    priority_queue<int> left; // max-heap
    priority_queue<int, vector<int>, greater<int>> right; // min-heap
    int x = 0, y = 0;

    // first window
    for (int i = 0; i < k; i++) {
        if (right.empty() || arr[i] > right.top()) {
            right.push(arr[i]); y++;
        } else {
            left.push(arr[i]); x++;
        }
        if (!isBalanced(x, y)) {
            if (x > y) {
                int t = left.top(); left.pop();
                right.push(t); x--; y++;
            } else {
                int t = right.top(); right.pop();
                left.push(t); y--; x++;
            }
        }
    }

    vector<double> result;
    result.push_back(getMedian(left, right, x, y));
    unordered_map<int, int> mp;

    for (int i = k; i < n; i++) {
        int newElementIndex = i;
        int oldElementToBeDeleted = i - k;

        double med = getMedian(left, right, x, y);

        if (arr[newElementIndex] > med) {
            right.push(arr[newElementIndex]); y++;
            if (!isBalanced(x, y)) {
                int t = left.top(); left.pop();
                right.push(t); x--; y++;
            }
        } else {
            left.push(arr[newElementIndex]); x++;
            if (!isBalanced(x, y)) {
                int t = right.top(); right.pop();
                left.push(t); y--; x++;
            }
        }

        mp[arr[oldElementToBeDeleted]]++;

        while (!left.empty() && mp[left.top()]) {
            mp[left.top()]--;
            left.pop(); x--;
            if (!isBalanced(x, y)) {
                int t = right.top(); right.pop();
                left.push(t); y--; x++;
            }
        }
        while (!right.empty() && mp[right.top()]) {
            mp[right.top()]--;
            right.pop(); y--;
            if (!isBalanced(x, y)) {
                int t = left.top(); left.pop();
                right.push(t); x--; y++;
            }
        }

        result.push_back(getMedian(left, right, x, y));
    }

    return result;
}

int main() {
    // Hardcoded input
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    int n = nums.size();

    vector<double> ans = sliding_median(nums, n, k);
    for (double val : ans) {
        cout << val << "\n";
    }

    return 0;
}
