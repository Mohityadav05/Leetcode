class Solution {
private:
    long long function(int mid,vector<int>& piles,int h){
        long long time=0;
        for(int i=0;i<piles.size();i++){
            time +=(piles[i]+mid-1)/mid;
        }
        return time;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        while(low<=high){
        int mid=low+(high-low)/2;
        long long midn=function(mid,piles,h);
        if(midn<=h){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
        }
        return ans;
    }
};