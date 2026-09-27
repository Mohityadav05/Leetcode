class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0;
        int cnt2=0;
        int ele1=0;
        int ele2=0;
        int n=nums.size();
        vector<int>ans;
        for(int val : nums){
            if(ele1==val){
                cnt1++;
            }else if(ele2==val){
                cnt2++;
            }else if(cnt1==0){
                ele1=val;
                cnt1=1;
            }else if(cnt2==0){
                ele2=val;
                cnt2=1;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(int val:nums){
            if(val==ele1) cnt1++;
            else if(val==ele2) cnt2++;
        }
        if(cnt1>n/3) ans.push_back(ele1);
        if(cnt2>n/3) ans.push_back(ele2);
        return ans;
    }
};