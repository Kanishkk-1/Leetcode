class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currproduct = 1;
        int maxproduct = nums[0];
        for(int i =0; i<n ;i++){
           currproduct *= nums[i];
            if(currproduct>maxproduct) maxproduct = currproduct;
            if(currproduct == 0) currproduct =1;
        }
currproduct =1;
        for(int i = n-1 ; i>=0 ;i--){
            currproduct *= nums[i];
             if(currproduct>maxproduct) maxproduct = currproduct;
            if(currproduct == 0) currproduct =1;
        }
        return maxproduct;
    }
};