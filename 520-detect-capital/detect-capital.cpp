class Solution {
public:
    bool detectCapitalUse(string word) {
        int countcapital=0;
        for(int i=0;i<word.size();i++){
            if(isupper(word[i])) countcapital++;
        }
        if(countcapital==0 || countcapital==word.size() ||
         (countcapital==1 &&isupper(word[0]))) return true;
        return false;
    }
};