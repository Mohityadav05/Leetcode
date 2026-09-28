class Solution {
public:
    int function(int mid, vector<int>& piles) {
        int totalhour = 0;

        for(int i = 0; i < piles.size(); i++) {
            totalhour += ceil((double)piles[i] / (double)mid);
        }

        return totalhour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int midn = function(mid, piles);

            if(midn <= h) {
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