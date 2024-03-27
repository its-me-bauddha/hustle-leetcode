class Solution {
public:
    void findConnections(int src,int parent,int&timer,vector<int>&tin,vector<int>&low
    , unordered_map<int,bool>&visited,vector<vector<int>>&ans, unordered_map<int,list<int> >&adjList){
        visited[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        for(auto nbr:adjList[src]){
            if(nbr == parent){
                continue;
            }
            if(!visited[nbr]){
                //dfs call
                 findConnections(nbr,src,timer,tin,low,visited,ans,adjList);
                // low update
                low[src] = min(low[src],low[nbr]);

                //check for bridge
                if(low[nbr]>tin[src]){
                    vector<int>temp;
                    temp.push_back(nbr);
                    temp.push_back(src);
                    ans.push_back(temp);

                }
            }
            else{
                //node is visited and not a parent
                // update the low
                low[src] = min(low[src],low[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int> >adjList;

        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }


        vector<int> tin(n);
        vector<int> low(n);
        vector<vector<int>>ans;
        int timer = 1;
        unordered_map<int,bool>visited;

        findConnections(0,-1,timer,tin,low,visited,ans,adjList);
        return ans;
    }
};