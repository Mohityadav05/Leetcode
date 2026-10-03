class Solution {
public:
    void function(int i,vector<vector<int>>& ans,vector<int>& nums,vector<int>& subset){
        if(i<0){
            ans.push_back(subset);
            return ;
        }
        subset.push_back(nums[i]);
        function(i-1,ans,nums,subset);
        subset.pop_back();
        while(i>0 && nums[i]==nums[i-1]){
            i--;
        }
        function(i-1,ans,nums,subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>subset;
        sort(nums.begin(),nums.end());
        function(n-1,ans,nums,subset);
        return ans;
    }
};