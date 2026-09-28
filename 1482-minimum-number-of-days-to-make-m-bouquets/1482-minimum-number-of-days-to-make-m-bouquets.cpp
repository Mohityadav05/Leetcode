class Solution {
public:
    int function(int mid,vector<int>& bloomDay,int m,int k){
        int total=0;
        int flower=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                flower++;
                if(flower==k){
                    total++;
                    flower=0;
                }
            }else{
                flower=0;
            }
        }
        return total;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int midn=function(mid,bloomDay,m,k);
            if(midn>=m){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};