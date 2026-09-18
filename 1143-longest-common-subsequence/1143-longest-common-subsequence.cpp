class Solution {
public:
    int function(int i, int j, string& text1, string& text2,
                 vector<vector<int>>& dp) {

        if(i < 0 || j < 0) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(text1[i] == text2[j]) {
            int take = 1 + function(i-1, j-1, text1, text2, dp);

            return dp[i][j] = take;
        }
        int not_take1 = function(i-1, j, text1, text2, dp);
        int not_take2 = function(i, j-1, text1, text2, dp);

        return dp[i][j] = max(not_take1, not_take2);
    }

    int longestCommonSubsequence(string text1, string text2) {

        int ind1 = text1.length();
        int ind2 = text2.length();

        vector<vector<int>> dp(ind1, vector<int>(ind2, -1));

        return function(ind1-1, ind2-1, text1, text2, dp);
    }
};