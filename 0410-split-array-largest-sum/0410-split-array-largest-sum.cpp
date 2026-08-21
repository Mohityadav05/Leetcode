class Solution {
public:
    int function(int mid,vector<int>& nums){
        int count=1;
        long long val=0;
        for(int i=0;i<nums.size();i++){
            if(val+nums[i]<=mid){
                val += nums[i];
            }else{
                count++;
                val=nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int sum=0;
        for(int val:nums){
            sum +=val;
        }
        int high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            int midN=function(mid,nums);
            if (midN > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};