class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long count=0;
        sort(happiness.begin(),happiness.end());
        long long i=happiness.size()-1;
        long long ans=0;
        while(k-- && happiness[i]-count>0 && i>=0){
            ans+=(happiness[i]-count);
            count++;
            i--;
        }
        return ans;
    }
};