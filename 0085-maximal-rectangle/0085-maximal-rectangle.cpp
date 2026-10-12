
class Solution {
private:
    int largehist(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n), nse(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                st.pop();
            }

            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();

            st.push(i);
        }

        int maxi = 0;

        for(int i = 0; i < n; i++) {
            maxi = max(maxi, heights[i] * (nse[i] - pse[i] - 1));
        }

        return maxi;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;

        int m = matrix[0].size();
        if(m == 0) return 0;

        vector<vector<int>> prefixsum(n, vector<int>(m, 0));

        for(int j = 0; j < m; j++) {
            int sum = 0;

            for(int i = 0; i < n; i++) {
                if(matrix[i][j] == '1') {
                    sum++;
                } else {
                    sum = 0;
                }

                prefixsum[i][j] = sum;
            }
        }

        int maxarea = 0;

        for(int i = 0; i < n; i++) {
            maxarea = max(maxarea, largehist(prefixsum[i]));
        }

        return maxarea;
    }
};
