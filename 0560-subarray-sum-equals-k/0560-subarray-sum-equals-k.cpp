class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr(n, 0);

        arr[0] = nums[0];
        for(int i = 1; i < n; i++) {
            arr[i] = arr[i - 1] + nums[i];
        }

        int count = 0;

        for(int i = 0; i < n; i++) {
            // Case 1: subarray from 0 to i
            if(arr[i] == k) count++;

            // Case 2: subarray from j+1 to i
            for(int j = 0; j < i; j++) {
                if(arr[i] - arr[j] == k) {
                    count++;
                }
            }
        }

        return count;
    }
};