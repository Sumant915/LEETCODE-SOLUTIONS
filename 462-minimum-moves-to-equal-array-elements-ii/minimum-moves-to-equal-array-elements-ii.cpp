class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        int mid=n/2;
        for(int i=0;i<mid;i++){
            int k=nums[mid]-nums[i];
            ans+=k;
        }
        for(int i=mid+1;i<n;i++){
            int k=nums[i]-nums[mid];
            ans+=k;
        }
        return ans;
    }
};