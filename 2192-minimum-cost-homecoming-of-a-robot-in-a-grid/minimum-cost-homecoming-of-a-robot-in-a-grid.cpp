
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {

        int ans = 0;

        int sr = startPos[0];
        int sc = startPos[1];

        int hr = homePos[0];
        int hc = homePos[1];

        // Row movement
        if(sr < hr) {
            for(int i = sr+1; i <= hr; i++)
                ans += rowCosts[i];
        }
        else {
            for(int i = sr-1; i >= hr; i--)
                ans += rowCosts[i];
        }

        // Column movement
        if(sc < hc) {
            for(int j = sc+1; j <= hc; j++)
                ans += colCosts[j];
        }
        else {
            for(int j = sc-1; j >= hc; j--)
                ans += colCosts[j];
        }

        return ans;
    }
};
