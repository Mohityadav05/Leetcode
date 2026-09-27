class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int flag=1;
        int val=nums[0];
        for(int i=1;i<nums.size();i++){
             if(flag==0){
                    val=nums[i];
                }
            if(nums[i]==val){
                flag++;
            }else{
                flag--;
            }
        }
        
        return val;
    }
};