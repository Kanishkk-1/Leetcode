class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int , int>mpp; int i;
        for(i=0 ; i<arr1.size() ; i++ )
        {
            mpp[arr1[i]]++;
        }
        arr1.clear();
        for(i=0; i<arr2.size() ; i++)
        {
              while(mpp[arr2[i]]>0)
              {
                arr1.push_back(arr2[i]);
                mpp[arr2[i]]--;
              }
              if(mpp[arr2[i]]==0)
              mpp.erase(arr2[i]);
        }
        for (const auto &pair : mpp) {
             {   int i=pair.second;
                while(i>0)
                  {arr1.push_back(pair.first);
                    i--;}
             
             }}

             return arr1;

       

    }
};