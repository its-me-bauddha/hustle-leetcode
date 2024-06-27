class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        for(int i=0;i<edges.size();i++){
            if( edges.size()>2 && edges[i][1] == edges[i+1][0] )
                return edges[i][1];
        }
        return edges[0][1] ;
    }
};