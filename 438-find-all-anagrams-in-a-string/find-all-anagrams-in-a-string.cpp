class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int start=0,end=0;
        unordered_map<char,int>m;
        vector<int>ans;
        for(int i=0;i<p.size();i++){
             m[p[i]]++;
        }
        int count=p.size();
        while(end<s.size()){
             m[s[end]]--;
             //matlab character p string me tha
             if(m[s[end]]>=0){
                    count--;
             }
             while(end-start+1==p.size()){
               if(count==0){
                ans.push_back(start);
               }
               //kya start wala char p me tha 
               if(m[s[start]]>=0){
                count++;
               }
                m[s[start]]++;
               start++;
             }
             end++;
        }
        return ans;
    }
};