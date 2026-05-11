class Solution {
public:
    int countAsterisks(string s) {
        bool flag=1;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*' && flag) count++;
            else if(s[i]=='|'){
                if(flag==0) flag=1;
                else flag=0;
            }
        }
        return count;
    }
};