class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>result;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            vector<int>temp;
            while(num){
                int last_digit=num%10;
                temp.push_back(last_digit);
                num=num/10;
            }
            for(int j=temp.size()-1;j>=0;j--){
                result.push_back(temp[j]);
            }
        }
        return result;
    }
};