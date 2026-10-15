class Solution {
private:
    int function(vector<int>& weights,int mid){
        int day=1;
        int wt=0;
        for(int i=0;i<weights.size();i++){
            if(wt+weights[i]<=mid){
                wt+=weights[i];
            }else{
                day++;
                wt=weights[i];
            }
        }
        return day;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(int i:weights){
            high +=i;
        }
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int midn=function(weights,mid);
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