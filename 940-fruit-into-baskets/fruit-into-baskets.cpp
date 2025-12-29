class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>m;
        int start=0,end=0;
        int unique=2;
        int ans=INT_MIN;
        while(end<fruits.size()){
            m[fruits[end]]++;
            if(m[fruits[end]]==1){
                unique--;
            }
            while(unique<0){
                ans=max(ans,end-start);
                m[fruits[start]]--;
                if(m[fruits[start]]==0){
                   unique++;
                }
                start++;
            }
            end++;
        }
        ans=max(ans,end-start);
        return ans;
    }
};