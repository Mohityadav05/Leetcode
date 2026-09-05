class Solution {
public:
    int function(int mid,vector<int>& nums,int threshold){
        int val=0;
        for(int i=0;i<nums.size();i++){
            val += ceil((double)nums[i]/(double)mid);
        }
        if(val<=threshold){
            return mid;
        }
        return -1;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            int midN=function(mid,nums,threshold);
            if(midN!=-1){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};