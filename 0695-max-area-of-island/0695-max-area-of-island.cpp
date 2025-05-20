class Solution {
public:

    static void dfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int &area, int i , int j){
     vis[i][j]  = 1;
     area++;

     int row = grid.size();
     int col = grid[0].size();

     int dirCol[] ={1,-1,0,0};
     int dirRow[] ={0,0,-1,1};

     for(int k=0;k<4;k++){
        int Col = j + dirCol[k];
        int Row = i + dirRow[k];

        if(Col >= 0  && Col < col &&
           Row >= 0  && Row < row &&
           vis[Row][Col] == 0 && grid[Row][Col] ==1){
            dfs(grid, vis, area, Row , Col);
           }
     }

     return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row,vector<int>(col,0));



        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                int AreaOfThisIsland = 0;
                dfs(grid,vis,AreaOfThisIsland,i,j);
                maxArea = max(AreaOfThisIsland,maxArea);
                }
            }
        }

        return maxArea;
    }
};