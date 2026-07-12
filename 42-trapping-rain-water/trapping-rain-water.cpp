class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int lmax=height[0];
        int rmax=height[n-1];
        int ans=0;
        int l=0,r=n-1;
        while(l<=r){
            lmax=max(height[l],lmax);
            rmax=max(height[r],rmax);
            if(lmax>rmax){
                ans+=rmax-height[r];
                r--;
            }
            else{
                ans+=lmax-height[l];
                l++;
            }   
        }
        return ans;
    }
};