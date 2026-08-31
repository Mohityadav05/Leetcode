class Solution {
public:
    // int picker(int n, int mid, int pick) {
    //     if (mid > pick) {
    //         return -1;
    //     }
    //     else if (mid < pick) {
    //         return 1;
    //     }
    //     else {
    //         return 0;
    //     }
    // }

    int guessNumber(int n) {
        int pick;  // not used

        int low = 1;
        int high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int midn = guess(mid);

            if (midn == -1) {
                high = mid - 1;
            }
            else if (midn == 1) {
                low = mid + 1;
            }
            else {
                return mid;
            }
        }

        return -1;
    }
};