class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> freq;
        unordered_map<char,bool> used;
        for(char x:s){
            freq[x]++;
            used[x]=false;
        }
        string st;
        for(int i=0;i<s.size();i++){
            char curr=s[i];
            freq[curr]--;

            if(used[curr]) continue;

            while(!st.empty() && st.back()>curr && freq[st.back()]>0){
                used[st.back()]=false;
                st.pop_back();
            }

            st.push_back(curr);
            used[curr]=true;
        }
        return st;
    }
};