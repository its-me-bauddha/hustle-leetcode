class Solution {
public:
    string compressedString(string word) {
        int n = word.length();
        string ans ="";
        int count = 1;
        for(int i=0;i<n;i++){
            if(word[i] == word[i+1] && count < 9 ){
                count++;
            }else{
                ans+= to_string(count) + word[i];
                count= 1;
            }
        }

        return ans;
    }
};