class Solution {
public:
    vector<string>ans;
    string mp[10]={
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    void comb(int index,string &digits,string curr){
        if(index==digits.size()){
            ans.push_back(curr);
            return;
        }
        string letters=mp[digits[index]-'0'];
        for(int i=0;i<letters.size();i++){
            curr.push_back(letters[i]);
            comb(index+1,digits,curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string curr = "";
        comb(0,digits,curr);
        return ans;
    }
};