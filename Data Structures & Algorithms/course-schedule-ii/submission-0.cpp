class Solution {
public:
    bool solve(vector<vector<int>>& adj,int node,vector<bool>& vis,vector<bool>& pathVis){
        vis[node]=true;
        pathVis[node]=true;
        for(auto& it:adj[node]){
            if(!vis[it]){
                if(solve(adj,it,vis,pathVis)==true){
                    return true;
                }
            }
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node]=false;
        return false;
    }
    void dfs(vector<vector<int>>& adj,int node,stack<int>& st,vector<bool>& vis){
        vis[node]=true;
        for(auto& it:adj[node]){
            if(!vis[it]){
                dfs(adj,it,st,vis);
            }
        }
        st.push(node);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> ans;
        vector<bool> viss(numCourses,false);
        vector<bool> pathVis(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!viss[i]){
                if(solve(adj,i,viss,pathVis)){
                    return {};
                }
            }
        }
        vector<bool> vis(numCourses,false);
        stack<int> st;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                dfs(adj,i,st,vis);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
