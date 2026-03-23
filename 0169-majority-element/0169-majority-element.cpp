class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int freq=1;
        int ans =nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]){
                freq++;
            }else{
                ans=nums[i];
                freq=1;
            }
            if(freq>nums.size()/2){
                return ans;
            }
        }
        return ans;
    }
};

