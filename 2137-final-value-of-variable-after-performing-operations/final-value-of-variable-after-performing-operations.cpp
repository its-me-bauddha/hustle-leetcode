class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        int val= 0;
       for(int i=0;i<op.size();i++)
        {
            if(op[i] == "X++" || op[i] == "++X")
             val++;
            else 
            val--;
        }
        return val;
    }
};