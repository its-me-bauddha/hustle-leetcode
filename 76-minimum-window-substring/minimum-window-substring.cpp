class Solution {
public:
    string minWindow(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        int start = 0;
        int ansIndex = -1;
        int ansLen = INT_MAX;

        if(len1 < len2) return "";

        unordered_map<char,int> sMap;
        unordered_map<char,int> tMap;

        // to keep all char of string t 
        for(int i=0;i<len2;i++){
            char ch = t[i];
            tMap[ch]++;

        }

        int count = 0; 
        for(int i=0 ; i<len1;i++){
            char ch = s[i];
            sMap[ch]++;
            
            if(sMap[ch] <= tMap[ch])
                count++;
            
            if(count == len2)
            {
               
                while(sMap[ s[start]] > tMap[ s[start]] || tMap[ s[start]] == 0){
                if(sMap[ s[start]] > tMap[ s[start]])
                    sMap[ s[start]]--;
                start++;
                
                 }

               // ans update 
                int windowLen = i - start + 1;
                if(windowLen < ansLen){
                ansLen = windowLen;
                ansIndex = start;
                }
            }
        }

        if(ansIndex == -1) return "";
        else
            return s.substr(ansIndex,ansLen);
    }
};