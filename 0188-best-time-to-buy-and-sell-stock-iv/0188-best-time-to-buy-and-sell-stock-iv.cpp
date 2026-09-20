class Solution {
public:
    int function(int i,int buy,int k,vector<int>& prices,int n,vector<vector<vector<int>>>& dp){
        if(i==n) return 0;
        if(k==0) return 0;
        if(dp[i][buy][k]!=-1){
            return dp[i][buy][k];
        }
        int profit=0;
        if(buy){
            profit=max(-prices[i]+function(i+1,0,k,prices,n,dp),function(i+1,1,k,prices,n,dp));
        }else{
            profit=max(prices[i]+function(i+1,1,k-1,prices,n,dp),function(i+1,0,k,prices,n,dp));
        }
        return dp[i][buy][k]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return function(0,1,k,prices,n,dp);
    }
};