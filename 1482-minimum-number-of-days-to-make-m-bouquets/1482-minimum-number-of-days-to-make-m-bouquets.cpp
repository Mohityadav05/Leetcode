class Solution {
public:
    int function(vector<int>& bloomDay, int m, int k,int mid){
        int no_boque=0;
        int count=0;
        int val=m*k;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                count++;
            }else{
                no_boque += count/k;
                count=0;
            }
        }
        no_boque += count/k;
        if(no_boque>=m){
            return mid;
        }
        return -1;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k > bloomDay.size()) {
            return -1;
        }
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            int midN=function(bloomDay,m,k,mid);
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