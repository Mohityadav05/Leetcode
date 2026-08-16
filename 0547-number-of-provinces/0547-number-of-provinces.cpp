class Solution {
public:
    void dfs(int i,int n,vector<bool>& vis,vector<vector<int>>& isConnected){
        vis[i]=true;
        for(int j=0;j<n;j++){
            if(isConnected[i][j] && !vis[j]){
                dfs(j,n,vis,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces=0;
        int n=isConnected.size();
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                provinces++;
                dfs(i,n,vis,isConnected);
            }
        }
        return provinces;
    }
};