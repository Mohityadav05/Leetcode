class Solution {
public:
    int function(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini=-1e9;
        for(int k=i;k<=j;k++){
            int cost=nums[i-1]*nums[k]*nums[j+1]+function(i,k-1,nums,dp)+function(k+1,j,nums,dp);
            mini=max(mini,cost);
        }
        return dp[i][j]=mini;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return function(1,n,nums,dp);
    }
};