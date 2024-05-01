class Solution {
public:
    string reversePrefix(string word, char ch) {
        int indexOfPrefix = -1;
        for(int i = 0 ; i < word.size();i++){
            if(word[i] == ch ){
                indexOfPrefix = i;
                break;
            }
        }


        reverse(word.begin(), word.begin() + indexOfPrefix+1);
        return word;
    }
};