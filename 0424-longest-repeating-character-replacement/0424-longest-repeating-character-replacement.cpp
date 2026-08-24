class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int maxlen=0;
        int maxfreq=0;
        unordered_map<char,int>mp;
        while(r<s.length()){
            mp[s[r]]++;
            maxfreq=max(maxfreq,mp[s[r]]);
            if((r-l+1)-maxfreq>k){
                mp[s[l]]--;
                maxfreq=0;
                l++;
            }
            if((r-l+1)-maxfreq<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};