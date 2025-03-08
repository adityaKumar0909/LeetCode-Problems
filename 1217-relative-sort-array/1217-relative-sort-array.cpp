class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // count frequencies of each
        map<int, int> map;
        for (auto x : arr1) {
            map[x]++;
        } 
       
        int n = arr1.size();
        vector<int> ans;

        for(auto &num:arr2){
            while(map[num] > 0){
            ans.push_back(num);
            map[num]--;
            }
            map.erase(num);
        }

        // for(auto &x:ans) cout<<x<<" ";

        for(auto &x:map){
            while(x.second-- > 0) {
                ans.push_back(x.first);
            }
        }

        return ans;

    }
};