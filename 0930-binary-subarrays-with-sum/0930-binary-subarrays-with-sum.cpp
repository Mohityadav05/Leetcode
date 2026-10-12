class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int>prefix(nums.size());
        prefix[0]=nums[0];
        int count=0;
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(prefix[i]==goal){
                count++;
            }
            int sum=prefix[i]-goal;
            if(mp.find(sum)!=mp.end()){
                count +=mp[sum];
            }
            mp[prefix[i]]++;
        }
        return count;
    }
};