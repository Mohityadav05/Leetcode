class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        int freq=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it : mp){
            if(it.second>freq){
                freq=it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};