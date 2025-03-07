class Solution {
public:

    static bool cmp(const pair<string,int> &a ,const pair<string ,int> &b){
        return a.second>b.second;
    }


    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        //create a pair for names and their corresponding heights
        vector<pair<string , int>> map;
        int n = names.size();

        for(int i=0;i<n;i++){
            map.emplace_back(names[i],heights[i]);
        }

        sort(map.begin(),map.end(),cmp);
        vector<string> ans;
        for(const auto &x:map){
            ans.push_back(x.first);
        }

        return ans;
    }
};