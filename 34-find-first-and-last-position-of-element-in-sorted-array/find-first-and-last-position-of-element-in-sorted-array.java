class Solution {
    public int[] searchRange(int[] nums, int target) {
        int start=0;
        int end=nums.length-1;
        int ans1=-1;
        int ans2=-1;

        while(start<=end){
        int mid=start+(end-start)/2;
        if(nums[mid]==target){
            ans1=mid;
            end=mid-1;
        }
        else if(nums[mid]>target){
             end=mid-1;
        }
        else{
            start=mid+1; 
        }
    }
    start=0;
    end=nums.length-1;
    while(start<=end){
        int mid=start+(end-start)/2;
         if(nums[mid]==target){
            ans2=mid;
            start=mid+1;
         }
         else if(nums[mid]>target){
            end=mid-1;
         }
         else{
            start=mid+1;
         }

    }
  int arr[] = new int[2];
  arr[0]=ans1;
  arr[1]=ans2;
return arr;
}
}