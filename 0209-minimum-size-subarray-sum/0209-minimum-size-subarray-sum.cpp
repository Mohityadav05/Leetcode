class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j=0;
        int currsum=0;
        int minlen=INT_MAX;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            while (currsum >= target) {
                minlen = min(minlen, i - j + 1);

                currsum -= nums[j];
                j++;
            }
        }
        if(minlen==INT_MAX){
            return 0;
        }
        return minlen;
    }
};