class Solution {
    private:
    void dfs(unordered_map<int,bool>&visited ,int src ,vector<vector<int>>& isConnected){
        visited[src] = true;
        int size = isConnected[src].size();
        for(int col=0;col<size;col++){
            if(src != col && isConnected[src][col] == 1){
                if(!visited[col]){
                    dfs(visited,col,isConnected);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,bool>visited;
        int n = isConnected.size();
        int count = 0 ;

        for(int i =1;i<=n;i++){
            if(!visited[i-1]){
                dfs(visited,i-1,isConnected);
                count++;
            }
        }
        return count;
    }
};