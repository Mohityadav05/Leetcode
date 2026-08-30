class Solution {
public:

    int largesthistogram(vector<int>& arr) {

        int n = arr.size();
        stack<int> st;
        int maxarea = 0;

        for(int i = 0; i <= n; i++) {

            int curr = (i == n) ? 0 : arr[i];

            while(!st.empty() && arr[st.top()] > curr) {

                int height = arr[st.top()];
                st.pop();

                int width;

                if(st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                maxarea = max(maxarea, height * width);
            }

            if(i < n)
                st.push(i);
        }

        return maxarea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        // Your prefixsum approach
        vector<vector<int>> prefixsum(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(matrix[i][j] == '1') {

                    if(i == 0)
                        prefixsum[i][j] = 1;
                    else
                        prefixsum[i][j] = prefixsum[i-1][j] + 1;

                }
                else {

                    prefixsum[i][j] = 0;
                }
            }
        }

        int maxarea = 0;

        for(int i = 0; i < n; i++) {

            maxarea = max(maxarea, largesthistogram(prefixsum[i]));

        }

        return maxarea;
    }
};