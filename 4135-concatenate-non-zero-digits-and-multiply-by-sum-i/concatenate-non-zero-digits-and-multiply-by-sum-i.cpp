class Solution {
public:
    long long sumAndMultiply(int n) {
        long long y=0;
        long long sum=0;
        while(n){
            long long r=n%10;
            if(r!=0){
                y=y*10+r;
                sum=sum+r;
            }
            n=n/10;
        }
        long long x=0;
        while(y){
            long long r=y%10;
            x=x*10+r;
            y=y/10;
        }
        return x*sum;
    }
};