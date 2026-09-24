class Solution {
public:
    int function(int i,vector<int>& nums,vector<int>& dp){
        if(i==0){
            return nums[0];
        }
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take=nums[i]+function(i-2,nums,dp);
        int not_take=function(i-1,nums,dp);
        return dp[i]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return function(n-1,nums,dp);
    }
};
