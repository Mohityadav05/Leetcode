class Solution {
public:
    void getcombination(int start,int n,int k,vector<vector<int>>& ans,vector<int> &combi){
        if(k==0){
            ans.push_back(combi);
            return;
        }
        for(int i=start;i<=n;i++){
            combi.push_back(i);
            getcombination(i+1,n,k-1,ans,combi);
            combi.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>combi;
        getcombination(1,n,k,ans,combi);
        return ans;
    }
};