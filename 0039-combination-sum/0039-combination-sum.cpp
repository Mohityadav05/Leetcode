class Solution {
public:
    set<vector<int>>st;
    void getAllCombination(vector<int>& candidates,int idx,int target,vector<vector<int>> &ans,vector<int> &combi){
        if(idx==candidates.size()||target<0){
            return;
        }
        if(target==0){
            if(st.find(combi)==st.end()){
                ans.push_back(combi);
                st.insert(combi);
            }
            return;
        }
        combi.push_back(candidates[idx]);
        getAllCombination(candidates,idx+1,target-candidates[idx],ans,combi);
        getAllCombination(candidates,idx,target-candidates[idx],ans,combi);
        combi.pop_back();
        getAllCombination(candidates,idx+1,target,ans,combi);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>combi;
        vector<vector<int>>ans;
        getAllCombination(candidates,0,target,ans,combi);
        return ans;
    }
};