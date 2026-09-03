class Solution {
public:
    set<vector<int>>st;
    void getpermuteUnique(vector<int>& nums,int idx,vector<vector<int>>& ans,vector<int> &combi){
        if(idx==nums.size()){
            if(st.find(combi)==st.end()){
            ans.push_back(combi);
            st.insert(combi);
            return;
        }
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            combi.push_back(nums[idx]);
            getpermuteUnique(nums,idx+1,ans,combi);
            combi.pop_back();
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>combi;
        getpermuteUnique(nums,0,ans,combi);
        return ans;
    }
};