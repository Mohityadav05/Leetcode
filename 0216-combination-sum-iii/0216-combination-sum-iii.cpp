class Solution {
public:
    void getCombination(int start,int k,int n,vector<vector<int>> &ans,vector<int> &combi){
        if(k==0 && n==0){
            ans.push_back(combi);
            return;
        }
        for(int i=start;i<=9;i++){
            combi.push_back(i);
            getCombination(i+1,k-1,n-i,ans,combi);
            combi.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>combi;
        getCombination(1,k,n,ans,combi);
        return ans;
    }
};