class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int r=mat.size();
        int sum=0;
        for(int i=0;i<r;i++){
            sum=sum+mat[i][i];
            sum=sum+mat[i][r-1-i];
        }
        if(r%2!=0) sum-=mat[r/2][r/2];
        return sum;
    }
};