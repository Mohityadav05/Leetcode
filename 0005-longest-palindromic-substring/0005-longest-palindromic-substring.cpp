class Solution {
public:
    string longestPalindrome(string s) {

        if (s.length() <= 1)
            return s;

        string ans = "";

        for (int i = 1; i < s.length(); i++) {

            // Odd length
            int low = i;
            int high = i;

            while (low >= 0 && high < s.length()
                   && s[low] == s[high]) {
                low--;
                high++;
            }

            string palindrome =
                s.substr(low + 1, high - low - 1);

            if (palindrome.length() > ans.length())
                ans = palindrome;

            // Even length
            low = i - 1;
            high = i;

            while (low >= 0 && high < s.length()
                   && s[low] == s[high]) {
                low--;
                high++;
            }

            palindrome =
                s.substr(low + 1, high - low - 1);

            if (palindrome.length() > ans.length())
                ans = palindrome;
        }

        return ans;
    }
};