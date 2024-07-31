class Solution {
public:
    int dp[1001];
    
    int ff(vector<vector<int>>& books, int lb, int w) {
        if (lb >= books.size())
            return 0;
        
        if (dp[lb] != -1) return dp[lb];
        
        int currWidth = w;
        int currHeight = 0;
        int minHeight = INT_MAX;
        int i;
        
        for (i=lb; i<books.size(); i++) {
            if (currWidth - books[i][0] >= 0) {
                currWidth -= books[i][0];
                currHeight = max(currHeight, books[i][1]);
                minHeight = min(minHeight, currHeight + ff(books, i + 1, w));
            }
            else break;
        }
        
        return dp[lb] = min(minHeight, currHeight + ff(books, i, w));
    }
     
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        memset(dp, -1, sizeof dp);
        return ff(books, 0, shelf_width);
    }
};