class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(char x:s){
            mp1[x]++;
        }
        for(char x:t){
            mp2[x]++;
        }
        for(char x:t){
            if(mp1.find(x)==mp1.end()){
                return x;
            }else if(mp1[x]!=mp2[x]){
                return x;
            }
        }
        return '0';
    }
};