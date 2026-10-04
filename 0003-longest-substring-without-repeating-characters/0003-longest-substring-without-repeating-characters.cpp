class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int n=s.length();
        unordered_map<char,int>mp;
        int maxlen=0;
        while(r<n){
            if(mp.find(s[r])!=mp.end()){
                if(mp[s[r]]>=l){
                    l=mp[s[r]]+1;
                }
            }
            maxlen=max(maxlen, r-l+1); 
            mp[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};