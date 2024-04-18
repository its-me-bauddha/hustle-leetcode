class Solution {
public:
     vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    void bfs(vector<vector<int>>& grid ,int i,int j ,int &peri){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int> >q;
        q.push({i,j});
        grid[i][j] = -1; //mark visited

        while(!q.empty()){
            auto front = q.front();
            q.pop();            
            
            for(auto & dir : directions){
                int i_ = front.first + dir[0];
                int j_ = front.second + dir[1];

                 if( i_ < 0 || i_ >= n || j_< 0 || j_ >= m || grid[i_][j_] == 0){
                 peri++;
        
                 }else if(grid[i_][j_] == -1)
                    continue;
                else{
                    q.push({i_,j_});
                    grid[i_][j_] = -1;
                }
            }
        }
         

    }
    void dfs(vector<vector<int>>& grid ,int i,int j ,int &peri){
         int n = grid.size();
        int m = grid[0].size();

        if( i < 0 || i >= n || j< 0 || j >= m || grid[i][j] == 0){
            peri++;
            return;
        }

        if(grid[i][j]== -1){
            return ;
        }

        grid[i][j] = -1 ;// mark visited 
        dfs(grid,i+1,j,peri); //right
        dfs(grid,i-1,j,peri); //left
        dfs(grid,i,j+1,peri); //top
        dfs(grid,i,j-1,peri); //bottom

    }
    int islandPerimeter(vector<vector<int>>& grid) {
       
        int n = grid.size();
        int m = grid[0].size();

        int perimeter = 0 ;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0) 
                 continue;

                if(j+1 >= m || grid[i][j+1] == 0 ){
                    perimeter++;
                }
                if(j-1 < 0 || grid[i][j-1] == 0 ){
                     perimeter++;
                }
                if(i-1 < 0 || grid[i-1][j] == 0){
                     perimeter++;
                }
                if(i+1>= n || grid[i+1][j] == 0 ){
                         perimeter++;
                }
            }
        }
        return perimeter;   
    }
};