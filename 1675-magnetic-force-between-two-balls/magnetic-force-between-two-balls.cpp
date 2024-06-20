class Solution {
public:
    bool possibleToPlace(int f ,vector<int>& pos, int m){
            int prev = pos[0] ;
            int countBalls = 1;

            for(int i =1; i< pos.size();i++){
                int curr =pos[i];
                if(curr -prev >= f){
                    countBalls++;
                    prev = curr;
                }
                if(countBalls == m)
                break;
                
            }
            
        return countBalls == m;
    }
    int maxDistance(vector<int>& pos, int m) {
        int n = pos.size();
        sort(begin(pos),end(pos));

        int minF = 1;
        int maxF = pos[n-1] - pos[0];

        int result = 0;
        while(minF <= maxF){
            int midF = minF  + (maxF - minF)/2;


            if(possibleToPlace(midF ,pos,m)){
                result = midF;
                minF = midF+1;
            }
            else{
                maxF = midF-1;
            }
        } 
        return result;
    }
};