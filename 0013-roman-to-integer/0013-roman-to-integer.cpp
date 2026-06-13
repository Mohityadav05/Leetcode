class Solution {
public:
    int romanToInt(string s) {
       unordered_map<char,int>mp={
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
       };
       int i=0;
       int j=i+1;
       int ans=0;
       for(int k=0;k<s.length();k++){
        if(mp[s[i]]<mp[s[j]]){
            ans = ans -mp[s[i]];
        }else{
            ans = ans+mp[s[i]];
        }
        i++;
        j++;
       } 
       return ans;
    }
};