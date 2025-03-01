class Solution {
public:
    //Count sort
    vector<int> countSort(vector<int>&arr, int range){
        vector<int> vec(range+1,0);
        for(auto x:arr) vec[x]++;

        vector<int> ans;

        for(int i=0;i<vec.size();i++){
            if(vec[i]>0){
                for(int j=0;j<vec[i];j++){
                    ans.push_back(i);
                }
            }
        }

        // for(auto x:ans)cout<<x<<" ";


        return ans;
    }
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {  
        int maxi = INT_MIN;
        for(auto x:arr) maxi = max(maxi,x);
        sort(arr.begin(),arr.end());
    
        int n = arr.size();
        arr[0]=1;

        int currentNum = arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]>1) arr[i] = arr[i-1]+1;
        }

        return arr[n-1];

        
        
    }
};