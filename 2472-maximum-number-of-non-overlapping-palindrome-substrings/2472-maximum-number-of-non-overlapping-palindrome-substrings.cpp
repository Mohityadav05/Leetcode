class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();

        // pal[l][r] = true if s[l...r] is palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Build palindrome table
        for (int l = n - 1; l >= 0; l--) {
            for (int r = l; r < n; r++) {

                if (s[l] == s[r] &&
                    (r - l <= 1 || pal[l + 1][r - 1])) {
                    pal[l][r] = true;
                }
            }
        }

        // dp[i] = maximum palindromes using first i characters
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            // Don't take a palindrome ending at i-1
            dp[i] = dp[i - 1];

            // Try every starting point
            for (int l = 0; l < i; l++) {

                int len = i - l;

                if (len < k)
                    continue;

                // O(1) palindrome check now
                if (pal[l][i - 1]) {
                    dp[i] = max(dp[i], dp[l] + 1);
                }
            }
        }

        return dp[n];
    }
};