class Solution {
public:
    bool solve(vector<vector<int>>& adj,vector<bool>& vis,vector<bool>& pathVis,int node){
        vis[node]=true;
        pathVis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(solve(adj,vis,pathVis,it)==true){
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            adj[b].push_back(a);
        }
        vector<bool> vis(numCourses,false);
        vector<bool> pathVis(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(solve(adj,vis,pathVis,i)){
                    return false;
                }
            }
        }
        return true;
    }   
};
