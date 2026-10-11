
class Solution {
private:
    void nextse(vector<int>& nums, stack<int>& st, vector<int>& nse) {
        for(int i = nums.size()-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if(st.empty()) nse[i] = nums.size();
            else nse[i] = st.top();

            st.push(i);
        }
    }

    void previousse(vector<int>& nums, stack<int>& st, vector<int>& pse) {
        for(int i = 0; i < nums.size(); i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();

            st.push(i);
        }
    }

    void nextge(vector<int>& nums, stack<int>& st, vector<int>& nge) {
        for(int i = nums.size()-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if(st.empty()) nge[i] = nums.size();
            else nge[i] = st.top();

            st.push(i);
        }
    }

    void previousge(vector<int>& nums, stack<int>& st, vector<int>& pge) {
        for(int i = 0; i < nums.size(); i++) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if(st.empty()) pge[i] = -1;
            else pge[i] = st.top();

            st.push(i);
        }
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();

        vector<int> nse(n), pse(n), nge(n), pge(n);

        nextse(nums, st, nse);
        while(!st.empty()) st.pop();

        previousse(nums, st, pse);
        while(!st.empty()) st.pop();

        nextge(nums, st, nge);
        while(!st.empty()) st.pop();

        previousge(nums, st, pge);

        long long mini = 0, maxi = 0;

        for(int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            mini += left * right * nums[i];

            left = i - pge[i];
            right = nge[i] - i;
            maxi += left * right * nums[i];
        }

        return maxi - mini;
    }
};
