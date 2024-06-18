class Solution {
public:
 void findCombination(int ind ,vector<vector<int>>&ans ,  vector<int>&ds ,  vector<int>& arr, int target){
    if(target==0){
            // sort(ds.begin(), ds.end());
            ans.push_back(ds);
        }
     for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i-1]) continue; // Skip duplicates
            if (arr[i] > target) break; // No need to continue if the current number is greater than the remaining target
            
            ds.push_back(arr[i]);
            findCombination(i + 1, ans, ds, arr, target - arr[i]);
            ds.pop_back();
        }

 }


public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        findCombination(0 , ans , ds , candidates , target);
        return ans;
    }
};