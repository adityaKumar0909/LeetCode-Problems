class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<int> freq(n*n+1,0);

        for(auto &row:grid){
           for(auto &ele:row){
            freq[ele]++;
           }
        }

        int missing = 0 ;
        int repeated = 0;
        for(int i=1;i<=n*n;i++){
            if(freq[i]>1) repeated = i;
            if(freq[i]==0) missing  = i;
        }

       return {repeated,missing};

    }
};