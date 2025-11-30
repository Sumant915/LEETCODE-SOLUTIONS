class Solution {
public:
    string compressedString(string word) {
        int i=0;
        string comp;
        int n=word.size();
        comp.reserve(n);
        while(i<n){
            char currchar=word[i];
            int count=0;
            while(i<n && word[i]==currchar){
                count++;
                i++;
            }
            if(count<=9){
                comp+=to_string(count);
                comp+=currchar;
            }
            else{
                while(count>9){
                    comp+='9';
                    comp+=currchar;
                    count=count-9;
                }
                comp+=to_string(count);
                comp+=currchar;
            }
        }
        return comp;
    }
};