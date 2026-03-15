class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool>visited(26,0);
        vector<int>lastidx(26,0);
        for(int i=0;i<s.size();i++){
            lastidx[s[i]-'a']=i;
        }
        stack<char>st;
        st.push(s[0]);
        visited[s[0]-'a']=1;
        for(int i=1;i<s.size();i++){
            if(visited[s[i]-'a']==0){
                    while(!st.empty() && s[i]<st.top()&& i<lastidx[st.top()-'a']) {
                        visited[st.top()-'a']=0;
                        st.pop();
                }
                st.push(s[i]);
                visited[s[i]-'a']=1;
            }
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};