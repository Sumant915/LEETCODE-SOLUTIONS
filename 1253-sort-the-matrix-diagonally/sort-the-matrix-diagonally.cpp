class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        for(int j=0;j<c;j++){
            vector<int>temp;
            int row=0,col=j;
            int rt=row,ct=col;
            while(row<r && col<c){
                temp.push_back(mat[row][col]);
                row++;
                col++;
            }
            int k=0;
            sort(temp.begin(),temp.end());
            while(k<temp.size() && rt<r && ct<c){
                mat[rt][ct]=temp[k];
                k++;
                rt++;
                ct++;
            }
        }

         for(int i=1;i<r;i++){
            vector<int>temp;
            int row=i,col=0;
            int rt=row,ct=col;
            while(row<r && col<c){
                temp.push_back(mat[row][col]);
                row++;
                col++;
            }
            int k=0;
            sort(temp.begin(),temp.end());
            while(k<temp.size() && rt<r && ct<c){
                mat[rt][ct]=temp[k];
                k++;
                rt++;
                ct++;
            }
        }
        return mat;
    }
};