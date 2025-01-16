class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.length()==0) return 0;

        vector<int> arr(256,0);
        int start = 0;
        int end = 0;
        int maxLength = INT_MIN;

        while(end<s.length()){
            int diff = s[end];
            arr[diff]++;
          
            while(arr[diff] > 1){
                int d = s[start];
                arr[d]--;
                start++;
               
            }
                
             
            maxLength = max(maxLength,end-start+1);
            
            end++;

        }


        

        return maxLength;
        
    }
};