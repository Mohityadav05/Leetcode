class Solution {
public:
    bool function(int i,string &s,vector<string>& wordDict,vector<int> &dp){
        if(i<0){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        for(string word  : wordDict){
            int len=word.length();
            int start=i-len+1;
            if(start>=0 &&s.substr(start,len)==word){
                if(function(start-1,s,wordDict,dp)){
                    return dp[i]=true;
                }
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<int>dp(n,-1);
        return function(n-1,s,wordDict,dp);
    }
};