class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int>temp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                temp.push_back(nums[i]);
            }
        }
        if(temp.size()==0) return nums;
        k=k%temp.size();
        int i=0,j=temp.size()-1;
        while(i<j){
            int dummy=temp[i];
            temp[i]=temp[j];
            temp[j]=dummy;
            i++,j--;
        }
        i=0,j=temp.size()-k-1;
        while(i<j){
            int dummy=temp[i];
            temp[i]=temp[j];
            temp[j]=dummy;
            i++,j--;
        }
         i=temp.size()-k,j=temp.size()-1;
        while(i<j){
            int dummy=temp[i];
            temp[i]=temp[j];
            temp[j]=dummy;
            i++,j--;
        }
        int idx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                nums[i]=temp[idx];
                idx++;
            }
        }
        return nums;
    }
};