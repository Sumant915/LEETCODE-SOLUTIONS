class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char,int>m;
        int count=0;
        int unique=3;
        int start=0,end=0;
        while(end<s.size()){
            m[s[end]]++;
            if(m[s[end]]==1){
                unique--;
            }
            while(end-start+1==3){
                if(unique==0){
                    count++;
                }
                m[s[start]]--;
                if(m[s[start]]==0) unique++;    
                start++;
            }
            end++;
        }
        return count;
    }
};