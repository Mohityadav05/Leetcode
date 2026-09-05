class Solution {
public:
    int function(int mid,vector<int>& weights,int days){
        int val=0;
        int day=1;
        for(int i=0;i<weights.size();i++){
            if(val+weights[i]<=mid){
                val += weights[i];
            }else{
                day++;
                val=weights[i];
            }
        }
        if(day<=days){
            return mid;
        }
        return -1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());;
        int high=0;
        for(int val :weights){
            high +=val;
        }
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            int midN=function(mid,weights,days);
            if(midN!=-1){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};