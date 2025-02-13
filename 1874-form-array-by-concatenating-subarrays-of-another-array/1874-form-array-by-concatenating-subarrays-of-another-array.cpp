class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {

        int i = 0;
        int j=0;
        while(i<groups.size() && j <nums.size()){
           
           if(j+groups[i].size() <= nums.size()  &&
           vector<int>(nums.begin()+j,nums.begin()+j+groups[i].size()) == 
           groups[i]){
            j+=groups[i].size();
            i++;
           }
           else{
            j++;
           }

        }

        return i==groups.size();
        
    }
};