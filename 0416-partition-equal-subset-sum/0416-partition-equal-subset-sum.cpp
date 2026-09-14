class Solution {
public:
    int function(int i,vector<int>& nums,int target,vector<vector<int>>& dp){
        if(i==0){
            return nums[0]==target;
        }
        if(target==0){
            return true;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int not_take=function(i-1,nums,target,dp);
        bool take =false;
        if(nums[i]<=target){
            take=function(i-1,nums,target-nums[i],dp);
        }
        return dp[i][target]=take||not_take;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums){
            sum +=i;
        }
        if(sum%2!=0){
            return false;
        }
        int n=nums.size();
        int target=sum/2;
        vector<vector<int>> dp(
            n,
            vector<int>(target + 1, -1)
        );
        return function(n-1,nums,target,dp);
    }
};