class Solution {
public:
    int function(int idx,vector<int>& nums,vector<int>& dp,int start){
        if(idx < start) {
            return 0;
        }

        if(idx == start) {
            return nums[start];
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int pick=nums[idx]+function(idx-2,nums,dp,start);
        int not_pick=0+function(idx-1,nums,dp,start);
        return dp[idx]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
       int n=nums.size();
       if(n==1) return nums[0];
       vector<int>dp1(n,-1);
       int case1=function(n-1,nums,dp1,1);
       vector<int>dp2(n,-1);
       int case2=function(n-2,nums,dp2,0);
       return max(case1,case2); 
    }
};