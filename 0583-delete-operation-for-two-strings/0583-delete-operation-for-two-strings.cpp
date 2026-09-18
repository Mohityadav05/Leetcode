class Solution {
public:
    int function(int i,int j,string& word1,string& word2,vector<vector<int>>& dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            int take=1+function(i-1,j-1,word1,word2,dp);
            return dp[i][j]=take;
        }
        int not_take1=function(i-1,j,word1,word2,dp);
        int not_take2=function(i,j-1,word1,word2,dp);
        return dp[i][j]=max(not_take1,not_take2);
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=function(n-1,m-1,word1,word2,dp);
        int operation=(n-ans)+(m-ans);
        return operation;
    }
};