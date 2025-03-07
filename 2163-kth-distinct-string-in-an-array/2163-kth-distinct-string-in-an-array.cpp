class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {

        unordered_map<string,int> map;

        for(auto &str:arr){
            map[str]++;
        }

        vector<string> unique;
        for(auto &x: arr){
            if(map[x] == 1) unique.push_back(x);
        } 

        if (unique.size() < k) return "";


        return unique[k-1];
        
    }
};