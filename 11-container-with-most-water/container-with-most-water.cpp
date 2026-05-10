class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxwater=INT_MIN;
        while(i<j){
            int water=0;
            if(height[i]<height[j]){
                 water=(height[i])*(j-i);
                 i++;
            }
            else{
                water=height[j]*(j-i);
                j--;
            }
            maxwater=max(water,maxwater);
        }
        return maxwater;
    }
};