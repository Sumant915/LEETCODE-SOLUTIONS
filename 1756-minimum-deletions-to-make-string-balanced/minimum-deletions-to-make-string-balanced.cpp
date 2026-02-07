class Solution {
public:
    int minimumDeletions(string s) {
        vector<int>prefixb(s.size(),0);
        vector<int>suffixa(s.size(),0);
        for(int i=1;i<s.size();i++){
            int isb=0;
            if(s[i-1]=='b') isb=1;
            prefixb[i]=prefixb[i-1]+isb;
        }
         for(int i=s.size()-2;i>=0;i--){
            int isa=0;
            if(s[i+1]=='a') isa=1;
            suffixa[i]=suffixa[i+1]+isa;
        }
        int ans=s.size();
        for(int i=0;i<s.size();i++){
            ans=min(ans,prefixb[i]+suffixa[i]);
        }
        return ans;
    }
};