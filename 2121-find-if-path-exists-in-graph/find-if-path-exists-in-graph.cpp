class Solution {
public:
    bool  check(unordered_map<int,vector<int>>&adj , int source,int destination, vector<bool>&visited){
        if(source == destination) return true;
        if(visited[source] == true) return false;

        visited[source] = true;

        for(auto & node:adj[source]){
            if(check(adj,node,destination,visited) == true)
                return true;
        }

        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> adj; // adjacency list 

        for(vector<int>& edge :edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>  visited(n,false);
        //return check(adj ,source,destination,visited);

        queue<int>q;
        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == destination) return true;

            for(auto & v : adj[node]){
                if(!visited[v] ){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        return false;
    }
};