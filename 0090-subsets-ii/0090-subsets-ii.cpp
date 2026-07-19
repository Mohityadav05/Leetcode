class Solution {
public:
    void getAllSubsets(vector<int>& nums,vector<int>& ans,int i,set<vector<int>>& allSubsets){
        if(i==nums.size()){
            allSubsets.insert(ans);
            return;
        }
        ans.push_back(nums[i]);
        getAllSubsets(nums,ans,i+1,allSubsets);
        ans.pop_back();
        getAllSubsets(nums,ans,i+1,allSubsets);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>allSubsets;
        vector<int>ans;
        getAllSubsets(nums,ans,0,allSubsets);
        return vector<vector<int>>(allSubsets.begin(), allSubsets.end());
    }
};