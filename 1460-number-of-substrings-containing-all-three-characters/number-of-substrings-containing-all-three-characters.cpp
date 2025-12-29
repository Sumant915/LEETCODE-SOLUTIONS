class Solution {
public:
    int numberOfSubstrings(string s) {
       unordered_map<char,int>m;
       int start=0,end=0;
       int count=0;
       int unique=3;
       while(end<s.size()){
          m[s[end]]++;
          if(m[s[end]]==1){
            unique--;
          }
          while(unique==0){
            count+=s.size()-end;
            m[s[start]]--;
            if(m[s[start]]==0){
                unique++;
            }
            start++;
          }
          end++;
       }
       return count;
    }
};