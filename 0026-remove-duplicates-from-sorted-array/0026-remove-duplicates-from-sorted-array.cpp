class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>box;
        box.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
           if(find(box.begin(),box.end(),nums[i])==box.end()){
            box.push_back(nums[i]);
           }
        }
        nums=box;
        return nums.size();
    }
};