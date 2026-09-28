class Solution {
public:
    int function(int mid,vector<int>& piles,int h){
        int val=0;
        for(int i=0;i<piles.size();i++){
            val +=ceil((double)piles[i]/(double)mid);
        }
        return val;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        while(low<high){
            int mid=low+(high-low)/2;
            int midN=function(mid,piles,h);
            if(midN<=h){
                ans=mid;
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};