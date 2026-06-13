class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char,int>mp;
       for(char ch:s){
        mp[ch]++;
       } 
       vector<pair<char,int>>ans;
       for(auto it:mp){
        ans.push_back({it.first,it.second});
       }
       sort(ans.begin(),ans.end(),[](pair<char,int>&a,pair<char,int>&b){
        return a.second>b.second;
       });
        string res="";
        for(auto it : ans){
            res += string(it.second,it.first);
        }
        return res;
    }
};
