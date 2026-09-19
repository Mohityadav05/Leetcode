class Solution {
public:
    int function(int i,int j,string& str1,string& str2,vector<vector<int>>& dp){
        if(i<0 || j<0){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(str1[i]==str2[j]){
            int take=1+function(i-1,j-1,str1,str2,dp);
            return dp[i][j]=take;
        }

        int not_take1=function(i-1,j,str1,str2,dp);
        int not_take2=function(i,j-1,str1,str2,dp);

        return dp[i][j]=max(not_take1,not_take2);
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        // function(n-1,m-1,str1,str2,dp);

        int i=n-1;
        int j=m-1;

        string ans="";

        while(i>=0 && j>=0){

            if(str1[i]==str2[j]){
                ans +=str1[i];
                i--;
                j--;
            }

            else if(function(i-1,j,str1,str2,dp) >
                    function(i,j-1,str1,str2,dp)){

                ans +=str1[i];
                i--;
            }

            else{
                ans +=str2[j];
                j--;
            }
        }

        while(i>=0){
            ans +=str1[i];
            i--;
        }

        while(j>=0){
            ans +=str2[j];
            j--;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};