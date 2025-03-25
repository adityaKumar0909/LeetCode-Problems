class Solution {
public:

    // int digits(int x){
    //     double num = log(x);
        

    // }

    int smallestRepunitDivByK(int k) {

        if(k%2==0 ) return -1;
        if(k%5==0 || k%10==0) return -1;

        int x = 0;
        int ans=0;
        while(true){
            // x = ((10*x)+1);
            // if(x%k==0) 
            // {   cout<<x<<endl;
            //     return log10(x)+1;
            // }

            x = ((10*x)+1)%k;
            ans++;
            if(x==0)
            {
                return ans;
            }

        }

        return -1;



        
    }
};