class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int> q; //queue to store starting index of active flips
        int flips=0;
        for(int i=0;i<nums.size();i++){
            if(!q.empty() && q.front()+k<=i){
                q.pop();
            }
            //checking flip count
            int no_of_flips=q.size()%2;
            int curr=nums[i];
            if(no_of_flips){
                curr=1-curr;
            }

            if(curr==0){
                if(i+k>nums.size()){
                    return -1;
                }
                q.push(i);
                flips++;
            }
        }
        return flips;
    }
};