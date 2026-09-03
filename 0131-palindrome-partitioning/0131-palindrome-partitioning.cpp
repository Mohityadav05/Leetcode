class Solution {
public:
    bool isPalindromic(string s){
        string s2=s;
        reverse(s2.begin(),s2.end());
        return s==s2;
    }
    void getAllparts(string s,vector<vector<string>>& ans,vector<string>& partition){
        if(s.size()==0){
            ans.push_back(partition);
            return;
        }
        for(int i=0;i<s.length();i++){
            string part=s.substr(0,i+1);
            if(isPalindromic(part)){
                partition.push_back(part);
                getAllparts(s.substr(i+1),ans,partition);
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>partition;
        getAllparts(s,ans,partition);
        return ans;
    }
};