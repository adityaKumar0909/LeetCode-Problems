class Solution {
public:

    static bool comp(vector<int> &a, vector<int>& b){
        return a[1]<b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {

        int len = 1;
        // int maxLen = INT_MIN;

        sort(pairs.begin(),pairs.end(),comp);
        int lastEle = pairs[0][1];

        int size = pairs.size();
        cout<<len<<endl;


        for(int i=1;i<size;i++){
            if(lastEle<pairs[i][0]) {
                
                len++;

                lastEle = pairs[i][1];
            }
            

            cout<<len<<endl;


        }

        return len;
        
    }
};