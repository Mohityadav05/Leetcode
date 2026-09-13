class Solution {
public:
    int function(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(j<0 || j>=matrix.size()){
            return 1e9;
        }
        if(i==0){
            return matrix[i][j];
        }
        if(dp[i][j]!=INT_MAX){
            return dp[i][j];
        }
        int up=matrix[i][j]+function(i-1,j,matrix,dp);
        int rightdiagonal=matrix[i][j]+function(i-1,j+1,matrix,dp);
        int leftdiagonal=matrix[i][j]+function(i-1,j-1,matrix,dp);
        return dp[i][j]=min(up,min(leftdiagonal,rightdiagonal));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        vector<vector<int>>dp(m,vector<int>(m,INT_MAX));
        int ans=1e9;
        for(int j=0;j<m;j++){
            ans=min(ans,function(m-1,j,matrix,dp));
        }
        return ans;
    }
};