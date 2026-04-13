class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        stack<int>st;
        int n=heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int element=heights[st.top()];
                st.pop();
                if(!st.empty()){
                    ans=max(ans,element*(i-st.top()-1));
                }
                else{
                    ans=max(ans,element*i);
                }
            }
            st.push(i);
        }
        while(!st.empty()){
                int element=heights[st.top()];
                st.pop();
                if(!st.empty()){
                    ans=max(ans,element*(n-st.top()-1));
                }
                else{
                    ans=max(ans,element*n);
                }
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>arr(matrix[0].size());
        int result=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='0'){
                    arr[j]=0;
                }
                else{
                    arr[j]+=1;
                }
            }
            result=max(largestRectangleArea(arr),result);
        }
        return result;
    }
};