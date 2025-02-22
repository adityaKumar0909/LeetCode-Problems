class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        // Transposing matrix
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    break;
                if (i != j)
                    swap(matrix[i][j], matrix[j][i]);
            }
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << matrix[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // Reversing Columns
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                // cout<<"swaaping ("<<i<<","<<j<<") with ("<<i<<","<<n-i-1<<")"<<endl; 
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << matrix[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
};