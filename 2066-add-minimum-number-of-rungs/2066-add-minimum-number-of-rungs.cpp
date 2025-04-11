class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {

        int count = 0 ;
        int size = rungs.size();
         if(rungs[0] > dist)
         count += (rungs[0] - 1 )/dist;

         //cout<<count;

        for(int i=1;i<size;i++){
            if(rungs[i] -  rungs[i-1] > dist){
                 count+= (rungs[i] - rungs[i-1] -1 )/dist;
                // count+=val;
            }
        }

        return count;
        
    }
};