class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        unordered_map<int,int> mpp ; //type:freq
        for(int i=0;i<n;i++){
            mpp[candyType[i]]++;
        }
        if(mpp.size()<=n/2) return mpp.size();
        return n/2;

    }
};