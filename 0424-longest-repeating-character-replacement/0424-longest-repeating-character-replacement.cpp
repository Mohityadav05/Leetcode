class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        unordered_map<char, int> mp;
        
        int maxlen = 0;
        int maxfreq = 0;

        while (r < s.length()) {
            mp[s[r]]++;

            maxfreq = max(maxfreq, mp[s[r]]);

            while ((r - l + 1) - maxfreq > k) {
                mp[s[l]]--;
                l++;

                // Recalculate max frequency
                maxfreq = 0;
                for (char ch = 'A'; ch <= 'Z'; ch++) {
                    maxfreq = max(maxfreq, mp[ch]);
                }
            }

            int len = r - l + 1;
            maxlen = max(maxlen, len);

            r++;
        }

        return maxlen;
    }
};