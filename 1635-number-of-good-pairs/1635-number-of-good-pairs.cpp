class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        //Create a map storing their last location 
        unordered_map<int , int > lastSeen;

        int n = nums.size();
        int count = 0;
        for(int i=0;i<n;i++){
            int num  = nums[i];
            if(lastSeen.count(num))
            count+=lastSeen[num];

            lastSeen[num]++;

        }
        
        return count;
        
    }
};