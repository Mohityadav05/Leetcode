class Solution {
public:
    int function(int i,int j,string& s,string& s1,vector<vector<int>>& dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s1[j]){
            int take=1+function(i-1,j-1,s,s1,dp);
            return dp[i][j]=take;
        }
        int not_take1=function(i-1,j,s,s1,dp);
        int not_take2=function(i,j-1,s,s1,dp);
        return dp[i][j]=max(not_take1,not_take2);
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string s1=s;
        reverse(s1.begin(),s1.end());
        int m=s1.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return function(n-1,m-1,s,s1,dp);
    }
};