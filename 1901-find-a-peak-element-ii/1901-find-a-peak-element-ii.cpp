class Solution {
public:
    int function(vector<vector<int>>& mat,int mid){
        int maxval=-1;
        int index=-1;
        for(int i=0;i<mat.size();i++){
            if(mat[i][mid]>maxval){
                maxval=mat[i][mid];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
       int n=mat.size();
       int m=mat[0].size();
       int low=0;
       int high=m-1;
       while(low<=high){
        int mid=low+(high-low)/2;
        int maxindex=function(mat,mid);
        int left = mid-1>=0 ? mat[maxindex][mid-1] : -1;
        int right = mid+1<m ? mat[maxindex][mid+1] : -1;
        if(mat[maxindex][mid]>left && mat[maxindex][mid]>right){
            return {maxindex,mid};
        }else if(mat[maxindex][mid]<left){
            high=mid-1;
        }else{
            low=mid+1;
        }
       }
       return {-1,-1};
    }
};