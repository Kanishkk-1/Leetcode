int result(vector<int>& v , int el){
    int n= v.size();
    int totalsum=0;
    for(int i=0;i<n;i++){
          totalsum += ceil((double)(v[i]) / (double)(el));
    }
    return totalsum;
}

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=INT_MIN;
        int mini= INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mini =min(mini,nums[i]);
            maxi =max(maxi,nums[i]);
        }
        int low= 1; 
        int ans;
        int high =maxi;
        while(low<=high){
        int mid = (low+high)/2;
       int sum = result(nums , mid);
        if(sum<=threshold){
          high=mid-1;
           
            

        }
        else{
            low=mid+1;
        }

        }
        return low;
    }
};