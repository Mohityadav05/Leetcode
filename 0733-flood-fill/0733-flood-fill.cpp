class Solution {
public:
    void bfs(int sr,int sc,int color,vector<vector<int>>& image,vector<vector<int>>& vis){
        queue<pair<int,int>>q;
        int original=image[sr][sc];
        vis[sr][sc]=1;
        image[sr][sc]=color;
        q.push({sr,sc});
        int n=image.size();
        int m=image[0].size();
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    if((abs(delcol)+abs(delrow))!=1){
                        continue;
                    }
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==original && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        image[nrow][ncol]=color;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        bfs(sr,sc,color,image,vis);
        return image;
    }
};