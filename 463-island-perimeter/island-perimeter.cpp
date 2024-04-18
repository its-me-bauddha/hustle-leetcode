class Solution {
public:
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
                if(grid[i][j] == 1){
                   dfs(grid,i,j,perimeter);
                }
            }
        }
        return perimeter;   
    }
};