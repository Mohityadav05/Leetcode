class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> mp;

        for (char ch : t) {
            mp[ch]++;
        }

        int l = 0;
        int r = 0;
        int count = 0;
        int minlen = INT_MAX;
        int sindex = -1;

        while (r < s.length()) {

            if (mp[s[r]] > 0) {
                count++;
            }
            mp[s[r]]--;

            while (count == t.size()) {

                if ((r - l + 1) < minlen) {
                    minlen = r - l + 1;
                    sindex = l;
                }

                mp[s[l]]++;

                if (mp[s[l]] > 0) {
                    count--;
                }

                l++;
            }

            r++;
        }

        return sindex == -1 ? "" : s.substr(sindex, minlen);
    }
};