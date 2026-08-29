class Solution {
public:
    vector<int> nse(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                nse[i] = -1;
            } else {
                nse[i] = st.top();
            }

            st.push(i);
        }

        return nse;
    }

    vector<int> nge(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                nge[i] = n;
            } else {
                nge[i] = st.top();
            }

            st.push(i);
        }

        return nge;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long total = 0;
        int mod = 1e9 + 7;

        vector<int> left = nse(arr);
        vector<int> right = nge(arr);

        for (int i = 0; i < n; i++) {
            long long l = i - left[i];
            long long r = right[i] - i;

            total = (total + (long long)arr[i] * l * r) % mod;
        }

        return total;
    }
};