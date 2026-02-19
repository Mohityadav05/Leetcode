class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        stack<int>s;
        for(int i=0;i<n;i++){
            s.push(nums2[i]);
        }
        for(int i=m;i<nums1.size();i++){
            nums1[i]=s.top();
            s.pop();
        }
        sort(nums1.begin(),nums1.end());
    }
};