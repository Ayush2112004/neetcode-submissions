class Solution {
public:
    void dfs(vector<vector<int>>& adj,int node,vector<bool>& vis){
        vis[node]=true;
        for(auto& n:adj[node]){
            if(!vis[n]){
                dfs(adj,n,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis);
                cnt++;
            }
        }
        return cnt;
    }
};
