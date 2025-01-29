class Solution {
public:
    int hIndex(vector<int>& arr) {

        sort(arr.begin(),arr.end());

        int count  = 0;

        int n = arr.size();

        if(n==1){

            if(arr[0]==0)
            return 0;

            return 1;

        } 

        for(int i = n-1;i>=0;i--){
            if(arr[i]!=0)
            count++;
            if(arr[i] <= count && arr[i]!=0)
            return arr[i];
        }

        // cout<<count;

        return count;
        
    }
};