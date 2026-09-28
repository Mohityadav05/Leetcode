class Solution {
public:
    int function(int mid,vector<int>& weights){
        int val=0;
        int day=1;
        for(int i=0;i<weights.size();i++){
            if(val+weights[i]<=mid){
                val +=weights[i];
            }else{
                day++;
                val=weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(int val:weights){
            high +=val;
        }
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int midn=function(mid,weights);
            if(midn<=days){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};