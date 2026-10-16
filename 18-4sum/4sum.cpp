class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n - 3; i++) {
            for(int j = i + 1; j < n - 2; j++) {
                int start = j + 1, end = n - 1;
                while(start < end) {
                    long long sum = (long long)nums[i] + nums[j]
                                  + nums[start] + nums[end];
                    if(sum == target) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[start]);
                        temp.push_back(nums[end]);
                        ans.push_back(temp);
                        start++;
                        end--;
                    }
                    else if(sum < target) {
                        start++;
                    }
                    else {
                        end--;
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};