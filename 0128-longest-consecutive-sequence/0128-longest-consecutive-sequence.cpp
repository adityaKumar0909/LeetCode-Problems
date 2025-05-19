class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s ; 
        for(auto &x:nums){
            s.insert(x);
        }
        vector<int> vec ; 
        for(auto &x:s){
            vec.push_back(x);
        }

        if(vec.empty()) return 0;
        
        int count  = 1;
        int size = vec.size();
        int maxCount = 0;
        for(int i=1;i<size;i++){
            if(vec[i] - vec[i-1] == 1  ){
                count++;
            }
            else{
                maxCount = max(maxCount, count);
                count = 1;
            }

        }
        maxCount = max(maxCount, count);
       
        return maxCount;
        
    }
};