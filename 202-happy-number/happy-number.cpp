class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>s;
        s.insert(n);
        while(n){
            int temp=n;
            int sum=0;
            while(temp){
            int r=temp%10;
            sum=sum+(r*r);
            temp=temp/10;
            }
            if(sum==1) return 1;
            if(s.count(sum)) return 0;
            s.insert(sum);
            n=sum;
        }
        return 0;
    }
};