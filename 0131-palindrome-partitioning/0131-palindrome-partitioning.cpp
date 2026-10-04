class Solution {
public:
    bool isPalindrome(int index,int i,string& s){
        while(index<=i){
            if(s[index]!=s[i]){
                return false;
            }
            index++;
            i--;
        }
        return true;
    }
    void function(int index,string& s,vector<string>& subset,vector<vector<string>>& ans){
        if(index==s.length()){
            ans.push_back(subset);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(isPalindrome(index,i,s)){
                subset.push_back(s.substr(index,i-index+1));
                function(i+1,s,subset,ans);
                subset.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>subset;
        function(0,s,subset,ans);
        return ans;
    }
};