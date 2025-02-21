class Solution {
public:
    int maxJump(vector<int>& stones) {

        vector<int> visited(stones.size(),-1);

        int maxJump = INT_MIN;
        int lastIndex = 0;
        int n=stones.size();
        for(int i=0;i<n;i++){
            maxJump = max(maxJump , stones[i] - stones[lastIndex] );
            visited[i] = 1;
            lastIndex = i;
            if(i!=n-2) i++; 
        }

        lastIndex = n-1;
        // maxJump = max(maxJump,stones[n-1] - stones[n-2]);
        for(int i=n-1;i>=0;i--){
            if(visited[i]==-1){
            maxJump = max(maxJump , abs(stones[i] - stones[lastIndex]) );
            lastIndex = i;
            }

        }

        return maxJump;
        
    }
};