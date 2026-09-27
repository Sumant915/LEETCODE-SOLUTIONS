class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                int start=st.top()+1;
                int end=i-1;
                while(start<=end){
                    if(s[start]=='(' || s[start]==')') start++;
                    else if(s[end]=='(' || s[end]==')') end--;
                    else{
                        char ch=s[end];
                        s[end]=s[start];
                        s[start]=ch;
                        start++,end--;
                    }
                }
                st.pop();
            }
        }
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]!='(' && s[i]!=')'){
                ans+=s[i];
            }
        }
        return ans;
    }
};