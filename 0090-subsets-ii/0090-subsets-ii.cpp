class Solution {
public:
    void function(int i, vector<int>& nums,
                  vector<int>& subset, vector<vector<int>>& ans) {

        if(i == nums.size()) {
            ans.push_back(subset);
            return;
        }

        // Take
        subset.push_back(nums[i]);

        function(i + 1, nums, subset, ans);

        subset.pop_back();

        // Not Take
        while(i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;

        function(i + 1, nums, subset, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> subset;
        vector<vector<int>> ans;

        function(0, nums, subset, ans);

        return ans;
    }
};