class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
       int temp=0;
       int n= nums.size();
       for(int i=0;i<n;i++){
           temp=temp+nums[i];
          nums[i]=temp;
       }
       return nums;
    }
     
};