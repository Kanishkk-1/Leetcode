int split(vector<int>& v, int minsum){
    int n=v.size();
    int totalsum=0;
    int subarray=1;
    for(int i=0;i<n;i++){
        if(totalsum+v[i]<=minsum){
            totalsum+=v[i];
        }
        else{
            subarray++;
            totalsum=v[i];
        }
    }
        return subarray;
}



class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int mini=INT_MIN; int sum=0;;
        for(int i=0;i<n;i++){
           mini=max(mini, nums[i]);
           sum+=nums[i];
        }
        int low=mini;
        int high=sum;
    
        while(low<=high){
            int mid=(low+high)/2;
            int p = split(nums,mid);
            if(p>k){
                low=mid+1;
            }
            else high=mid-1;
        }
        return low;
    }
};