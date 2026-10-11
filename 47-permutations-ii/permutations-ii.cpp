class Solution {
public:
    void permut(vector<int>&arr,int index,set<vector<int>>&st){
    if(index==arr.size()){
        st.insert(arr);
        return;
    }
    for(int i=index;i<arr.size();i++){
       swap(arr[i],arr[index]);
       permut(arr,index+1,st);
       swap(arr[i],arr[index]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>st;
        vector<vector<int>>ans;
        permut(nums,0,st);
        for (auto&v:st) {
            ans.push_back(v);
        }
        return ans;
    }
};