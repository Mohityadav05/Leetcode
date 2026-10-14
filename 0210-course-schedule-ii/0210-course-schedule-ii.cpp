class Solution {
private:
    bool dfs(int node,vector<int>& vis,vector<int>& pathvis,vector<vector<int>>& adj,stack<int>& st){
        vis[node]=1;
        pathvis[node]=1;
        for(int it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathvis,adj,st)==true){
                    return true;
                }
            }else if(pathvis[it]){
                return true;
            }
        }
        pathvis[node]=0;
        st.push(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(numCourses,0);
        vector<int>pathvis(numCourses,0);
        stack<int>st;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathvis,adj,st)){
                    return{};
                }
            }
        }
        vector<int>ans;
        while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
        }

        return ans;
    }
};