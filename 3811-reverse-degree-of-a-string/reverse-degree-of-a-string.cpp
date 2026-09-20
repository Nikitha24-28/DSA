class Solution {
public:
    int reverseDegree(string s) {
        int rev_idx;
        int sum=0;
        for(int i=0;i<s.size();i++){
            rev_idx=('z'-s[i])+1;
            sum+=(rev_idx*(i+1));
        }
        return sum;
    }
};