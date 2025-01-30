class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {

        int size = s.length();
        
        int left = -1;
        vector<int> nextL(size,0);
        int right = -1;
        vector<int> nextR(size,0);

        vector<int> prefixSum(size,0);

        vector<int> ans;

        for(int i=0;i<s.length();i++){

          if(s[i]=='|')
          left = i;

          nextL[i] = left;
        }

        for(int i=s.length()-1;i>=0;i--){

            if(s[i]=='|')
            right = i;

            nextR[i] = right;
        }
         
        int count = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '*')
            count++;

            prefixSum[i] = count;
            
        }

        for(int i=0;i<queries.size();i++){

            int start = nextR[queries[i][0]];
            int end  = nextL[queries[i][1]];

           if (start != -1 && end != -1 && start < end)
{

            int leftElement  = prefixSum[start];
            int rightElement  =  prefixSum[end];
            int diff = rightElement  - leftElement ;
            ans.push_back(diff);

            }
            else{

                ans.push_back(0);
            }

        }

        return ans;
        
    }
};