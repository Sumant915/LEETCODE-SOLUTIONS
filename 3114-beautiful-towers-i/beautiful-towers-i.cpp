class Solution {
public:
   void maxsum(vector<int>heights,long long max_idx,long long &sum){
         for(int i=max_idx-1;i>=0;i--){
              heights[i]=min(heights[i],heights[i+1]);
        }
         for(int i=max_idx+1;i<heights.size();i++){
              heights[i]=min(heights[i],heights[i-1]);
        }
        long long currsum=0;
        for(int i=0;i<heights.size();i++){
            currsum+=heights[i];
        }
        sum=max(currsum,sum);
   }
    long long maximumSumOfHeights(vector<int>& heights) {
        long long sum=0;
        for(int i=0;i<heights.size();i++){
            maxsum(heights,i,sum);
        }
        return sum;
    }
};