class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,vector<int>> map;

        for(int i=1;i<=n;i++){
            int num = i;
            int digitSum=0;
            while(num>0){
                digitSum+=num%10;
                num/=10;
            }
            map[digitSum].push_back(i);
        }

        //Find max group size
        int maxGroupSize=INT_MIN;
        for(auto &x:map){
            int size = x.second.size();
            if(size>maxGroupSize) maxGroupSize = size;
        }
        int count = 0;
          for(auto &x:map){
            int size = x.second.size();
            if(size==maxGroupSize) count++;
        }

        

        return count;


    }
};