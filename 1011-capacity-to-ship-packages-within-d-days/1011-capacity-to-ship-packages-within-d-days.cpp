class Solution {
public:
    int function(int mid,vector<int>& weights,int days){
        int day=1;
        int load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>mid){
                day=day+1;
                load=weights[i];
            }else{
                load +=weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int n=weights.size();
        int high=0;
        for(int val :weights){ high +=val;}
        while(low<=high){
            int mid=low+(high-low)/2;
            int midN=function(mid,weights,days);
            if(midN<=days){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};