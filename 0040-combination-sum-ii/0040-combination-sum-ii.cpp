class Solution {
public:
    void function(int idx,vector<int>& candidates, int target,vector<int>& subset,vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(subset);
            return ;
        }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i] > target)
                break;
            subset.push_back(candidates[i]);
            function(i+1,candidates,target-candidates[i],subset,ans);
            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>subset;
        vector<vector<int>>ans;
        function(0,candidates,target,subset,ans);
        return ans;
    }
};