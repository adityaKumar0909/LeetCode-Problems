class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {

        vector<vector<int>> arr(m, vector<int>(n,0));
        int size = original.size();
        if(m==1 && n==1 && size!=1)return {};
        if( size  % (m*n) != 0) return {};
        if(size > (m*n)) return {};


        int index = 0;
        for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(index<size)
            arr[i][j] = original[index++];
            else break;
        }
        }

        return arr;
    }
};