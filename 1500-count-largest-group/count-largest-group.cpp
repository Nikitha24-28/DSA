class Solution {
public:
    int add_digits(int n){
        int sum = 0;
        while(n){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        vector<int> freq(37,0);
        for(int i=1;i<=n;i++){
            int idx=add_digits(i);
            freq[idx]++;
        }
        int maxi=0;
        for(int i=1;i<37;i++){
            maxi=max(maxi,freq[i]);
        }
        int count=0;
        for(int i=1;i<37;i++){
            if(freq[i]==maxi) count++;
        }
        return count;
    }
};