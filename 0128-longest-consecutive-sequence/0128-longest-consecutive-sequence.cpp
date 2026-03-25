class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        vector<int>ans(st.begin(),st.end());
        int maximum=1;
        int count =1;
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i+1]-ans[i] !=1){
                count=1;
            }else{
                count++;
            }
            maximum=max(maximum,count);
        }
        return maximum;
    }
};