class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n=boxGrid.size();
        int m=boxGrid[0].size();
    for(int i=0;i<n;i++){
        int left=m-1;
        int right=m-1;
        while(right>=0){
               if(boxGrid[i][right]=='.') right--;

               else if(boxGrid[i][right]=='#'){
                swap(boxGrid[i][right],boxGrid[i][left]);
                left--,right--;
               }  

               else{
                right--;
                left=right;
               }
        }
    }
    vector<vector<char>>ans(m,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[j][n-1-i]=boxGrid[i][j];
        }
    }
    return ans;
    }
};