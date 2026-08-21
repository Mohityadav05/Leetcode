class Solution {
public:
    int function(int mid,vector<int>& bloomDay,int m,int k){
        int count=0;
        int noboque=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                count++;
            }else{
                noboque += count/k;
                count=0;
            }
        }
        noboque += count / k; 
        return noboque >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = 1LL * m * k;

        // not enough flowers
        if(val > bloomDay.size()) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            int midN=function(mid,bloomDay,m,k);
            if(midN){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};