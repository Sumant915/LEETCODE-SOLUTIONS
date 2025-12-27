class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        for(int i=0;i<t.size();i++){
            m[t[i]]++;
        }
        int start=0,end=0,index=-1,total=t.size(),ans=INT_MAX;
        while(end<s.size()){
            m[s[end]]--;
            if(m[s[end]]>=0){
                total--;
            }
            //decrease window size if total==0 or !total;
            while(!total && start<=end){
                 if(ans>end-start+1){
                    ans=end-start+1;
                    index=start;
                 }
                 m[s[start]]++;
                 if(m[s[start]]>0){
                    total++;
                 }
                 start++;
            }
            end++;
        }
        if(index==-1){
            return "";
        }
        string result="";
        while(ans--){
            result+=s[index];
            index++;
        }
        return result;
    }
};