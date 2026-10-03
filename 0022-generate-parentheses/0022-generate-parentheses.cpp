class Solution {
public:
    void function(int i,int open,int close,string combi,vector<string>& ans){
        if(combi.length()==2*i){
            ans.push_back(combi);
            return ;
        }
        if(open<i){
            function(i,open+1,close,combi+'(',ans);
        }
        if(close<open){
            function(i,open,close+1,combi+')',ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        function(n,0,0,"",ans);
        return ans;
    }
};