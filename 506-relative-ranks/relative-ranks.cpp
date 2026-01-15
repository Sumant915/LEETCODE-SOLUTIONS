class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int>p;
        for(int i=0;i<score.size();i++){
            p.push(score[i]);
        }
        unordered_map<int,string>m;
        int count=1;
        while(!p.empty()){
            if(count==1) m[p.top()]="Gold Medal";
           else if(count==2) m[p.top()]="Silver Medal";
           else if(count==3) m[p.top()]="Bronze Medal";
            else m[p.top()]=to_string(count);
            count++;
            p.pop();
        }
        vector<string>ans;
        for(int i=0;i<score.size();i++){
            ans.push_back(m[score[i]]);
        }
        return ans;
    }
};