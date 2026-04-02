class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        stack<int>st;
        stack<int>st1;
        int n=nums.size();
        vector<int>arange;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>0){
            st.push(nums[i]);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]<0){
            st1.push(nums[i]);
            }
        }
        while(!st.empty() && !st1.empty()){
            arange.push_back(st.top());
            st.pop();
            arange.push_back(st1.top());
            st1.pop();
        }
        nums=arange;
        return nums;
    }
};