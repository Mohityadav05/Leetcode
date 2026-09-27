class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int count=0;
        vector<int>prefix;
        unordered_map<int,int>mp;
        prefix.push_back(nums[0]);
        for(int i=1;i<n;i++){
            prefix.push_back(prefix.back()+nums[i]);
        }
        for(int i=0;i<n;i++){
            if(prefix[i]==k) count++;
            int sum=prefix[i]-k;
            if(mp.find(sum)!=mp.end()){
                count +=mp[sum];
            }
                mp[prefix[i]]++;
        }
        return count;
    }
};