class Solution {
public:

    int findMax(vector<int> &piles){

        int maxi = INT_MIN;

        for(int i = 0; i < piles.size(); i++){
            maxi = max(maxi, piles[i]);
        }

        return maxi;
    }

    long long calculateHours(vector<int> &piles, int hourly){

        long long totalhr = 0;

        for(int i = 0; i < piles.size(); i++){

            totalhr += ceil((double)piles[i] / (double)hourly);
        }

        return totalhr;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = findMax(piles);

        while(low <= high){

            int mid = low + (high - low) / 2;

            long long totalhr = calculateHours(piles, mid);

            if(totalhr <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};