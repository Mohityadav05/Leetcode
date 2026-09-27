class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        int pos=0;
        int neg=1;
        for(int val:nums){
            if(val>=0){
                ans[pos]=val;
                pos=pos+2;
            }else{
                ans[neg]=val;
                neg=neg+2;
            }
        }
        return ans;
    }
};