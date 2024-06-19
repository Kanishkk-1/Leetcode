class Solution {
public:
void rec(int arr[],int ind,int s,vector<vector<int>>&ans,
vector<int>&temp,int k,int n)
{
    if(ind==s)
    {
        if(n==0 && temp.size()==k)
        ans.push_back(temp);
        return;
    }
    if(n>=arr[ind])
    {
        temp.push_back(arr[ind]);
        rec(arr,ind+1,s,ans,temp,k,n-arr[ind]);
        temp.pop_back();
    }
        rec(arr,ind+1,s,ans,temp,k,n);
}
    vector<vector<int>> combinationSum3(int k, int n) {
        int arr[]={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>temp;
        int s=9;
        rec(arr,0,s,ans,temp,k,n);
        return ans;
    }
};