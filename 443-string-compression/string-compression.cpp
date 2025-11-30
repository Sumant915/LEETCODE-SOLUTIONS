class Solution {
public:
    int compress(vector<char>& chars) {
       int idx=0;
       int i=0;
       int n=chars.size();
       while(i<n){
           char currchar=chars[i];
           int count=0;
           while(i<n && chars[i]==currchar){
               i++;
               count++;
           }
           chars[idx]=currchar;
           idx++;
           if(count>1){
            string cnt=to_string(count);
            for(int j=0;j<cnt.size();j++){
                chars[idx++]=cnt[j];
            }
         }
       }
       return idx;
    }
};