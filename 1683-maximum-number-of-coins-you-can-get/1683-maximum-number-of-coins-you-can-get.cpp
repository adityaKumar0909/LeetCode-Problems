class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());

        int n = piles.size();

        int sum = 0;
        int pile = n/3;
        int count=0;

        for(int i=n-2;i>=0;i-=2){
            cout<<piles[i]<<endl;
            sum+=piles[i];
            count++;
            if(count==pile) break;
        }

        return sum;
        
    }
};