class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string temp;
            int n=s.size()%k;
            n+=s.size()/k;
            for(int i=0;i<s.size();i+=k){
                int sum=0;
                // for(int j=i;j<i+k;j++){
                //     sum+=s[j]-'0';
                // }
                int j=i;
                while(j<i+k && j<s.size()){
                     sum+=s[j]-'0';
                     j++;
                }
                temp=temp+to_string(sum);
            }
            s=temp;
        }
        return s;
    }
};