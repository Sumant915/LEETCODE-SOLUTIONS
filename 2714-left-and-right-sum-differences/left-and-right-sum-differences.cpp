class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>answer;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int leftsum=0;
        for(int i=0;i<nums.size();i++){
            int rightsum=sum-nums[i]-leftsum;
            answer.push_back(abs(leftsum-rightsum));
            leftsum+=nums[i];
        }
        return answer;
    }
};