class Solution {
public:
    vector<int> nse(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                nse[i] = n;
            } else {
                nse[i] = st.top();
            }

            st.push(i);
        }

        return nse;
    }

    vector<int> nge(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
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

    vector<int> pse(vector<int>& nums) {
        int n = nums.size();
        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                pse[i] = -1;
            } else {
                pse[i] = st.top();
            }

            st.push(i);
        }

        return pse;
    }

    vector<int> pge(vector<int>& nums) {
        int n = nums.size();
        vector<int> pge(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                pge[i] = -1;
            } else {
                pge[i] = st.top();
            }

            st.push(i);
        }

        return pge;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftsmall = pse(nums);
        vector<int> rightsmall = nse(nums);

        vector<int> leftgreater = pge(nums);
        vector<int> rightgreater = nge(nums);

        long long maximum = 0;
        long long minimum = 0;

        for (int i = 0; i < n; i++) {

            // Minimum contribution
            long long left = i - leftsmall[i];
            long long right = rightsmall[i] - i;

            minimum += 1LL * nums[i] * left * right;

            // Maximum contribution
            left = i - leftgreater[i];
            right = rightgreater[i] - i;

            maximum += 1LL * nums[i] * left * right;
        }

        return maximum - minimum;
    }
};