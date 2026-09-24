class Solution {
public:
    int function(int i,vector<int>& nums,vector<int>& dp,int start){
        if(i<start) return 0;
        if(i==start){
            return nums[start];
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take=nums[i]+function(i-2,nums,dp,start);
        int not_take=function(i-1,nums,dp,start);
        return dp[i]=max(not_take,take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n,-1);
        int case1= function(n-2,nums,dp1,0);
        vector<int>dp2(n,-1);
        int case2=function(n-1,nums,dp2,1);
        return max(case1,case2);
    }
};