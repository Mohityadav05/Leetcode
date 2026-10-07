class Solution {
public:
    void dfs(int sr, int sc, int color,
             vector<vector<int>>& image,
             vector<vector<int>>& vis) {
        
        int original = image[sr][sc];
        
        vis[sr][sc] = 1;
        image[sr][sc] = color;
        
        int n = image.size();
        int m = image[0].size();
        
        for(int delrow = -1; delrow <= 1; delrow++) {
            for(int delcol = -1; delcol <= 1; delcol++) {
                
                if(abs(delcol) + abs(delrow) != 1) {
                    continue;
                }
                
                int nrow = sr + delrow;
                int ncol = sc + delcol;
                
                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   image[nrow][ncol] == original &&
                   !vis[nrow][ncol]) {
                    
                    dfs(nrow, ncol, color, image, vis);
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                   int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        if(image[sr][sc] == color)
            return image;
        
        dfs(sr, sc, color, image, vis);
        
        return image;
    }
};