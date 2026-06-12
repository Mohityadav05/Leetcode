class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        for(char ch1 : s){
            m1[ch1]++;
        }
        for(char ch2 : t){
            m2[ch2]++;
        }
        for(auto it:m1){
            if(m2[it.first] != it.second){
            return false;
        }
        }
        return true;
    }
};