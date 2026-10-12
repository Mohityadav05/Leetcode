class Solution {
private:
    int function(vector<int>& nums,int k){
        int l=0;
        int r=0;
        int sum=0;
        int count=0;
        while(r<nums.size()){
            sum+=nums[r]%2;
            while(sum>k){
                sum =sum-nums[l]%2;
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return function(nums,k)-function(nums,k-1);
    }
};