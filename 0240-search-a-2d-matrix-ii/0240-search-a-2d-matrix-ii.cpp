class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        if(m==0 || n==0) return false;

        //Starting index  ( right most element in top row)
        int row = 0;
        int col = n-1;

        while(row < m && col >=0){
            //If matches return true
            if(matrix[row][col] == target) return true;
            //If bigger go left
            else if(matrix[row][col] > target ) col--;
            //if smaller go down
            else row++;
        }     
        //If we are out of matrix , this means we didnt found target
        return false;
    }
};