class Solution {
public:
    int function(int i,vector<int>& nums,int target,vector<vector<int>>& dp){
         if(i == 0) {
            if(target == 0 && nums[0] == 0) {
                return 2;
            }

            if(target == 0 || target == nums[0]) {
                return 1;
            }

            return 0;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int not_take=function(i-1,nums,target,dp);
        int take=0;
        if(nums[i]<=target){
            take=function(i-1,nums,target-nums[i],dp);
        }
        return dp[i][target]=take+not_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i :nums){
            sum +=i;
        }if(sum < abs(target)) {
            return 0;
        }
        if((sum + target) % 2 != 0) {
            return 0;
        }

        int newTarget = (sum + target) / 2;

        vector<vector<int>> dp(
            n,
            vector<int>(newTarget + 1, -1)
        );

        return function(n - 1, nums, newTarget, dp);
    }
};