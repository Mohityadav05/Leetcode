class Solution {
public:
    int function(vector<int>& piles, int h, int mid) {
        long long sum = 0;

        for (int val : piles) {
            sum += (val + mid - 1) / mid;
        }

        if (sum <= h)
            return 1;

        return 0;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int midN = function(piles, h, mid);

            if (midN == 1) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};