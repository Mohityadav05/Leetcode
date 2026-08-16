class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int val:nums){
            mp[val]++;
        }
        vector<int>ans;
        for(auto it : mp){
            ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());
         for (int i = 0; i < ans.size(); i++) {
            nums[i] = ans[i];
        }

        return ans.size();
    }
};