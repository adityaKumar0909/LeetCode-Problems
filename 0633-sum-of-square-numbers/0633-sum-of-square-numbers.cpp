class Solution {
public:
    bool judgeSquareSum(int c) {

        // if(c<=1) return false;

        int left=0;
        int right=sqrt(c);
        while(left<=right){

            long long leftSquareVal = (long long)left*left;
            long long rightSquareVal = (long long)right*right;


            long long val=leftSquareVal + rightSquareVal;
            cout<<val<<" ";

            if(val==c)return true;
            else if(val>c)right--;
            else  left++;

            // cout<<left<<" "<<right<<endl;

        }

        return false;
        
    }
};