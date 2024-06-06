  int  findMax(vector<int>& v){
    int n=v.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
      maxi=max(maxi,v[i]);
        }
        return maxi;
}

int findTotalHours(vector<int>& v ,int hourly){
int n=v.size();
 int th=0;

for(int i=0;i<n;i++){
    if (hourly > 0) {
            th += (v[i] + hourly - 1) / hourly; // Equivalent to ceil((double)(v[i]) / (double)(hourly))
        } else {
            // This should not happen due to our binary search logic
            return INT_MAX; // Return a large number to indicate invalid rate
        }
}
return th;
}

class Solution {
    



public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=0,high=findMax(piles);

        while(low<=high){
            int mid=(low+high)/2;
            int totalhrs= findTotalHours(piles , mid);

            if(totalhrs <= h){
                high= mid-1;
            }

            else{
                low=mid+1;
            }
}
        return low;
    }
};