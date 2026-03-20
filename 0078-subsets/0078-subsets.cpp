#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(int index, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
        // Add current subset
        ans.push_back(curr);

        // Explore further elements
        for (int i = index; i < nums.size(); i++) {
            curr.push_back(nums[i]);      // include
            solve(i + 1, nums, curr, ans);
            curr.pop_back();              // backtrack
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, nums, curr, ans);
        return ans;
    }
};
