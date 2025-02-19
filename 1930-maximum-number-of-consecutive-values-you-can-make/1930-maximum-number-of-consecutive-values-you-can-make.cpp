class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {

        sort(coins.begin(),coins.end());
        int p=0;

        for(auto x:coins){

            if(x>p+1) break;
            p+=x;

        }

        return p+1;
        
    }
};