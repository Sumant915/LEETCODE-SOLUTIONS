class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<int>());
       int total_apple=0;
        for(int i=0;i<apple.size();i++){
            total_apple+=apple[i];
        }
        int sum=0;
        for(int i=0;i<capacity.size();i++){
            sum+=capacity[i];
            if(sum>=total_apple){
                return i+1;
            }
        }
        return -1;
    }
};