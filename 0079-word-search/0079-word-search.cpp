class Solution {
public:
bool wordSearch(int ind  ,vector<vector<char>>& board ,string  word ,int row ,  int col ,int  m ,int n){
    if(ind==word.size()){
        return true;
    }

    if (row < 0 || col < 0 || row == m || col == n || board[row][col] != word[ind] || board[row][col] == '!')
        return false;

    char c = board[row][col];
    board[row][col] = '!';

    bool top = wordSearch( ind+1 , board , word , row-1 ,  col ,  m , n);
    bool right = wordSearch( ind+1 , board , word , row ,  col+1 ,  m , n);
    bool bottom = wordSearch( ind+1 , board , word , row+1 ,  col ,  m , n);
    bool left = wordSearch( ind+1 , board , word , row ,  col-1 ,  m , n);

  board[row][col] = c;

    return top|| right || bottom || left;
}

    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int temp;
        // wordSearch(0 ,temp , board , word);
        int m = board.size();
        int n= board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0]==board[i][j]){
                    if(wordSearch(0 , board , word , i , j , m , n)) return true;
                       
                }
            }
        }


    return false;

    }
};