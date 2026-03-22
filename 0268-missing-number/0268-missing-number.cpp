class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=(n*(n+1))/2;
        int total =0;
        for(int val : nums){
            total=total+val;
        }
        return (sum-total);
    }
};