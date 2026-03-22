class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> box;
        
        box.push_back(nums[0]);
        
        for(int i = 1; i < nums.size(); i++){
            if(box.back() == nums[i]){
                continue;
            }
            box.push_back(nums[i]);
        }

        // copy back to original array
        for(int i = 0; i < box.size(); i++){
            nums[i] = box[i];
        }

        return box.size();
    }
};