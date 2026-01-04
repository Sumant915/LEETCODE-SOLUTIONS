class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>ans(code.size(),0);
        if(k==0) return ans;
        for(int i=0;i<code.size();i++){
            int count=k;
            while(count){
                int index=(i+count+code.size())%code.size();
                ans[i]+=code[index];
                if(k<0) count++;
                else count--;
              }
         }
        return ans;
    }
};