class Solution {
public:
    int largestInteger(int num) {
        vector<int> odd;
        vector<int> even;
        vector<int> nums;
        while(num){
            nums.push_back(num%10);
            num/=10;
        }
        reverse(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                even.push_back(nums[i]);
            }else{
                odd.push_back(nums[i]);
            }
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        vector<int> ans_vec(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                ans_vec[i]=even[even.size()-1];
                even.pop_back();
            }else{
                ans_vec[i]=odd[odd.size()-1];
                odd.pop_back();
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=(ans*10)+ans_vec[i];
        }
        return ans;
    }
};