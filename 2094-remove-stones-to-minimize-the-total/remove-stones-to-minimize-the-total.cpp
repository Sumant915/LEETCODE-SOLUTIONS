class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>p;
        for(int i=0;i<piles.size();i++){
            p.push(piles[i]);
        }
        while(!p.empty() && k){
            int max=p.top();
            p.pop();
            if(max%2==0) p.push(max/2);
            else p.push((max/2)+1);
            k=k-1;
        }
        int total_stones=0;
        if(k==0){
            while(!p.empty()){
                total_stones+=p.top();
                p.pop();
            }
        }
        return total_stones;
    }
};