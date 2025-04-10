class Solution {
public:

    long long solve(long long n){
    if(n==1)return 0;
    if(n==3)return 2;
    if(n%2==0)return solve(n/2)+1;
    else{
        if(((n+1)/2)%2==0)return 1+solve(n+1);
        else return 1+solve(n-1);
    }
    
}
    int integerReplacement(int n) {
        
        return solve((long long)n);
    }
};