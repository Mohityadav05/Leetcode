class Solution {
public:
    bool isIsomorphic(string s, string t) {
        for(int i=0;i<s.length();i++){
            char c1=s[i];
            char c2=t[i];
            for(int j=0;j<s.length();j++){
                if(s[j]==c1 && t[j]!=c2){
                    return false;
                }
                if(s[j]!=c1 && t[j]==c2){
                    return false;
                }
            }
        }
        return true;
    }
};