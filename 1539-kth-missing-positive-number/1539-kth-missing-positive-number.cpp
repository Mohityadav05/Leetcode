class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=k){
                k++;
            }else{
                return k;
            }
        }
        return k;
    }
};