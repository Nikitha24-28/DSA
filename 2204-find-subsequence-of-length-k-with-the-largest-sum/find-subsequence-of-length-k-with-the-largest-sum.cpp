class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        vector<vector<int>> topk;
        int i=1;
        while(!pq.empty() && i<=k){
            auto top_ele=pq.top();pq.pop();
            vector<int> v={top_ele.second,top_ele.first};
            topk.push_back(v);
            i++;
        }
        sort(topk.begin(),topk.end());
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(topk[i][1]);
        }
        return ans;
    }
};