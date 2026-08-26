class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int>mp;
        int n=grid.size();
        vector<int>ans;
        int a;
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum += grid[i][j];
                if(mp.find(grid[i][j])!=mp.end()){
                a=grid[i][j];
                }
                mp[grid[i][j]]++;
            }
        }
        int nsum=n*n*(n*n+1)/2;
        int b=nsum-(sum-a);
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};