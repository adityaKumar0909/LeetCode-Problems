class Solution {
public:

    bool ifPossible(vector<int>candies,int num, int k){

       long long count = 0;
       for(int i=candies.size()-1;i>=0;i--){
        if(candies[i]>=num) count+=candies[i]/num;
       }
        cout<<count<<endl;
        cout<<"for "<<num<<" "<<(count>=k)<<endl;
        return count>=k;

    }

    int maximumCandies(vector<int>& candies, long long k) {

        sort(candies.begin(),candies.end());
        long long sum = 0;
        for(auto x:candies)sum+=x;

        int start = 1;
        int end = sum/k;

        cout<<"start:"<<start<<endl;
        cout<<"end:"<<end<<endl;
        cout<<endl;

        if(end==0) return 0;
        
        while(start<=end){
            int mid=start + (end-start)/2;

            if(ifPossible(candies,mid,k)){
                start=mid+1;

            }
            else{
                end = mid-1;

            }

        }

        cout<<"start:"<<start<<endl;
        cout<<"end:"<<end<<endl;


        return start-1;
        
    }
};