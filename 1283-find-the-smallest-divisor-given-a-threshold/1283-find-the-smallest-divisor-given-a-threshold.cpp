class Solution {
private:
    int function(vector<int>& nums,int mid){
        int val=0;
        for(int i=0;i<nums.size();i++){
            val +=(nums[i]+mid-1)/mid;
        }
        return val;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
    int low=1;
    int high=*max_element(nums.begin(),nums.end());
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int midn=function(nums,mid);
        if(midn<=threshold){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
    }
};