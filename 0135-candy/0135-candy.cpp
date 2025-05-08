class Solution {
public:
    int candy(vector<int>& ratings) {


        int size = ratings.size();
        vector<int> candies(size,1);

        int prev;
        int curr;
        int next;

        if(size ==1 ) return 1;
        int count = 0;

        for(int i = 1;i<size;i++){
         prev = ratings[i-1];
         curr = ratings[i];
       

         if(prev<curr){
            candies[i] = candies[i-1]+1;
         }
         
        }

        for(int i=size-2;i>=0;i--){
            next = ratings[i+1];
            curr = ratings[i];

            if(next<curr)
            candies[i] = max(candies[i],candies[i+1]+1);
            

        }

        for(auto x:candies){
            count+=x;
            cout<<x<<" ";        }



        return count;
        
    }
};