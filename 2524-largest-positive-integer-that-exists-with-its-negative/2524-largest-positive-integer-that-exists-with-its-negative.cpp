class Solution {
public:
    int findMaxK(vector<int>& nums) {

        unordered_set<int> map;
        int maxNum=INT_MIN;

        for(auto &num:nums){
            if(map.find(-1*num)!=map.end()){
                maxNum = max(abs(num),maxNum);
            }
            else{
                map.insert(num);
            }
        }


        return maxNum == INT_MIN ? -1 : maxNum;
        
    }
};