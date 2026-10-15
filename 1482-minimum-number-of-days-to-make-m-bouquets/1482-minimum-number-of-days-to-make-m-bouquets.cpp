class Solution {
private:
    int function(int mid,vector<int>& bloomDay,int m,int k){
        int flower=0;
        int boque=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                flower++;
                if(flower==k){
                    boque++;;
                    flower=0;
                }
            }else{
                flower=0;
            }
        }
        return boque;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int mid=low+(high-low)/2;
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