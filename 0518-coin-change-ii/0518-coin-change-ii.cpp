class Solution {
public:
    int function(int i,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(amount==0){
            return 1;
        }
        if(i==0){
            if(amount % coins[0] == 0) {
                return 1;
            }
            return 0;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int not_take=function(i-1,amount,coins,dp);
        int take=0;
        if(coins[i]<=amount){
            take=function(i,amount-coins[i],coins,dp);
        }
        return dp[i][amount]=take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return function(n-1,amount,coins,dp);
    }
};