class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxlen = 0;

        for(int unique = 1; unique <= 26; unique++) {
            int l = 0;
            int r = 0;
            int good = 0;

            unordered_map<char,int> mp;

            while(r < s.length()) {

                mp[s[r]]++;

                if(mp[s[r]] == k) {
                    good++;
                }

                while(mp.size() > unique) {
                    if(mp[s[l]] == k) {
                        good--;
                    }

                    mp[s[l]]--;

                    if(mp[s[l]] == 0) {
                        mp.erase(s[l]);
                    }

                    l++;
                }

                if(mp.size() == unique && good == unique) {
                    maxlen = max(maxlen, r - l + 1);
                }

                r++;
            }
        }

        return maxlen;
    }
};