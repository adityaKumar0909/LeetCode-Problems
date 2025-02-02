class Solution {
public:
    
    int checkdays(vector<int>& nums, int weight){
        int sum = 0;
        int count = 1;
        for(int i=0;i<nums.size();i++){
            if(sum + nums[i]>weight){
                count++;
                sum = nums[i];
            }
            else {
                sum+=nums[i];
            }
        }
        
 
        // //cout<<"for weight : "<<weight<<" it took  "<<" ";
        // if(sum>0&&sum<weight) count++;
        // // cout<<count<<" days"<<endl;
        // // cout<<"Sum left: "<<sum<<endl;
        return count;
    }
    int splitArray(vector<int>& nums, int k) {

        int max = INT_MIN;
        int sum = 0;
        for(auto x:nums){
            if(x>max)max = x;
            sum+=x;
        }

        int s = max;
        int e = sum;
        int ans = sum;
        while(s<=e){
            int mid = (s + e)/2;
            int daysTook = checkdays(nums,mid);
            if(daysTook<=k){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            // cout<<s<<" "<<e<<endl;
        }

        return s;
        
    }
};