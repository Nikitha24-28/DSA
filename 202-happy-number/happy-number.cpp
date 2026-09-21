class Solution {
public:
    bool isHappy(int n) {
        if(n==1 || n==7) return true;
        if(n<=9) return false;
        int copy=n;
        int sum=0;
        while(copy){
            int a=copy%10;
            sum+=(a*a);
            copy/=10;
        }
        return isHappy(sum);
    }
};