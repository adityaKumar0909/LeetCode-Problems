class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int unique = 0;
        int s = 0;
        int e = 0;
        int maxWindow = INT_MIN;

        unordered_map<int,int> mpp;

        while(e<fruits.size()){
           //Increase it's frequency
            mpp[fruits[e]]++;


            //Dekho ki yeh unique ya nhi 
            if(mpp[fruits[e]] == 1)
            unique++;


            // if(s<e && unique > 2){
                while(unique > 2){

                    if(mpp[fruits[s]] == 1)
                    unique--;

                    mpp[fruits[s]]--;
                    s++;


                    
                }

                

            // }

            maxWindow = max(maxWindow , e-s+1);
            

            e++;

        }



        return maxWindow;

    }
};