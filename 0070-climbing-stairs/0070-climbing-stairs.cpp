class Solution {
public:
    int function(int idx,int n,vector<int>& dp){
        if(idx==0){
            return 1;
        }
        if(idx==1) return 1;
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int way1=function(idx-1,n,dp);
        int way2=function(idx-2,n,dp);
        return dp[idx]=way1+way2;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return function(n,n,dp);
    }
};