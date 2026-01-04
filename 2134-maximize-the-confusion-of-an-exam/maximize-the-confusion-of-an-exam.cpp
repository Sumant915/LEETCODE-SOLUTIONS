class Solution {
public:
    int maxlength(string answerKey,int k,char target,int &ans){
        int start=0,end=0;
        int n=answerKey.size();
        int count=0;
        while(end<n){
            if(answerKey[end]!=target) count++;
            while(count>k){
                 ans=max(ans,end-start);
                 if(answerKey[start]==answerKey[end]) count--;
                 start++;
            }
            end++;
        }
        ans=max(ans,end-start);
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans=0;
        maxlength(answerKey,k,'T',ans);
        maxlength(answerKey,k,'F',ans);
        return ans;
    }
};