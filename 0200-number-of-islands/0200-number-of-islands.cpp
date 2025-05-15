class Solution {
public:

    static void dfs(vector<vector<int>> &visited, vector<vector<char>>& grid,int n, int m){
        //Mark current coordinate visited
        visited[n][m] = 1;

        int rowSize = grid.size();
        int colSize = grid[0].size();

        int rowDir[] = {-1,1,0,0};
        int colDir[] = {0,0,-1,1};

        for(int i=0;i<4;i++){
           
                int newRow = n + rowDir[i];
                int newCol = m + colDir[i];
                if( newRow >=0 && newRow < rowSize && newCol >=0 && newCol<colSize 
                &&
                !visited[newRow][newCol] && grid[newRow][newCol]=='1'){
                    dfs(visited , grid, newRow, newCol);
                }
            
        }

        


    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));


        int count = 0;


        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(visited,grid,i,j);
                    count++;
                }
            }
        }
        
        return count;
    }
};