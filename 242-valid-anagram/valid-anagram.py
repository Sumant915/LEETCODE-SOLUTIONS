class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if(len(s)!=len(t)):
            return False
        dict={}
        for i in s:
            dict[i]=dict.get(i,0)+1
        for i in t:
            if i not in dict:
                return False
            dict[i]-=1
            if dict[i]<0:
                return False
        return True