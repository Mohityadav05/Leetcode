class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=0;
        int flag=0;
        for(int i=0;i<nums.size();i++){
            if(flag==0){
                ans=nums[i];
            }
            if(nums[i]==ans){
                flag++;
            }else{
                flag--;
            }
        }
        return ans;
    }
};