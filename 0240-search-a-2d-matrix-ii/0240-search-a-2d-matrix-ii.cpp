class Solution {
public:
    bool binary(int row,int col,vector<vector<int>>& matrix, int target){
        int low=0;
        int high=col-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[row][mid]==target){
                return true;
            }else if(matrix[row][mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool search=false;
        for(int i=0;i<n;i++){
            search=binary(i,m,matrix,target);
            if(search==true){
                return true;
            }
        }
        return search;
    }
};