class Solution {
public:
    long long function(int mid, vector<int>& piles, int h) {
        long long val = 0;

        for(int i = 0; i < piles.size(); i++) {
            val += ceil((double)piles[i] / (double)mid);
        }

        return val;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            long long midN = function(mid, piles, h);

            if(midN <= h) {
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