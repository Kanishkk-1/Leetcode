class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        int sum=0;
        for(auto x:nums){
            if(m.find(x)==m.end())
            m[x]=1;
            else
            m[x]++;
        }

        for(auto x:m){
           int n = x.second;
            for(int i=n-1; i>0;i--){
                sum+=i;
            }
            
        }
         return sum;
    }
};