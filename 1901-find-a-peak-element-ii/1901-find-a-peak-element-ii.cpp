class Solution {
public:
    int findmaxrow_element(int mid, vector<vector<int>>& mat, int n, int m) {
        int maxelement = -1;
        int index = -1;

        for (int i = 0; i < n; i++) {
            if (mat[i][mid] > maxelement) {
                maxelement = mat[i][mid];
                index = i;
            }
        }

        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int maxrow = findmaxrow_element(mid, mat, n, m);

            int left = (mid - 1 >= 0) ? mat[maxrow][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[maxrow][mid + 1] : -1;

            if (mat[maxrow][mid] > left &&
                mat[maxrow][mid] > right) {
                return {maxrow, mid};
            }

            if (left > mat[maxrow][mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};