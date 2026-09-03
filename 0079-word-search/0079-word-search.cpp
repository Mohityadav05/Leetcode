class Solution {
public:
    bool findpath(vector<vector<char>>& board,string& word,int row,int col,int index,vector<vector<bool>>& vis){
        int m=board.size();
        int n=board[0].size();
        if(row <0|| col<0||row>=m || col>=n || vis[row][col]==true||board[row][col]!=word[index]){
            return false;
        }
        if(index==word.length()-1){
            return true;
        }
        vis[row][col]=true;
        bool ans=
        findpath(board,word,row-1,col,index+1,vis)||
        findpath(board,word,row+1,col,index+1,vis)||
        findpath(board,word,row,col-1,index+1,vis)||
        findpath(board,word,row,col+1,index+1,vis);
        vis[row][col]=false;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (findpath(board, word, i, j, 0, vis)) {
                    return true;
                }
            }
        }

        return false;
    }
};