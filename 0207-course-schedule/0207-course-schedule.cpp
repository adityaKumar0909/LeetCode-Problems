class Solution {
public:

    static bool dfs(int i , vector<vector<int>>& adj, vector<bool> &visited, vector<bool> & pathSeenInThisCycle){
        visited[i]  = true;
        pathSeenInThisCycle[i] = true;

        for(auto &x:adj[i]){
            if(!visited[x])
            {
                if(dfs(x,adj,visited,pathSeenInThisCycle)) return true;
            }

            else if(pathSeenInThisCycle[x]) return true;
        }
        
        //Changing route , after going to a differnet branch
        pathSeenInThisCycle[i] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prereq) {

        vector<vector<int>> adj(n);
        for(auto &x:prereq){
            adj[x[1]].push_back(x[0]); 
        }
        vector<bool> visited(n,false);
        vector<bool> pathSeenInThisCycle(n,false);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,pathSeenInThisCycle)) return false;

            }
        }



        return true;


    }
};