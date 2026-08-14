class Solution {
public:
    void dfs(int i,int j,int orgcolor,int newcolor,vector<vector<int>>& image){
        if(i<0 ||j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=orgcolor || image[i][j]==newcolor){
            return;
        }
        image[i][j]=newcolor;
        dfs(i-1,j,orgcolor,newcolor,image);
        dfs(i,j+1,orgcolor,newcolor,image);
        dfs(i+1,j,orgcolor,newcolor,image);
        dfs(i,j-1,orgcolor,newcolor,image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(sr,sc,image[sr][sc],color,image);
        return image;
    }
};