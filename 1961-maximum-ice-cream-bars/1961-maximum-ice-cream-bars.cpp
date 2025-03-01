class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int count = 0;
        int n=costs.size();
        for(int i=0;i<n;i++){
            coins -= costs[i];
            if(coins>=0) count++;
            if(coins<0) break;
        }

        return count;
        
    }
};