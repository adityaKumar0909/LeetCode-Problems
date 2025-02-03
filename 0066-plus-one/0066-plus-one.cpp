class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        // int carry = 0;
        int n = digits.size();
        int sum = (digits[n-1]+1)%10;
        int carry = (digits[n-1]+1)/10;
        digits[n-1] = sum;

        vector<int> ans;
        ans.push_back(sum);

        
        for(int i = digits.size()-2;i>=0;i--){
    
            sum  =  ( digits[i] + carry )%10;
            carry = ( digits[i] + carry )/10;
             ans.push_back(sum);
 
            
        }

        if(carry>0){

        ans.push_back(carry);

            
        }

        reverse(ans.begin(),ans.end());

        return ans;

        
    }
};