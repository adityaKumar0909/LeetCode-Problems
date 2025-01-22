class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {

        vector<int> arr = colors;

        int toPlace = colors.size();
        //Flattening circular array

        for(int i = 0;i<toPlace;i++){
            arr.push_back(colors[i]);
        }

       for(auto x: arr){
        cout<<x<<" ";
       }
       
        int start = 0;
        int count1=0;
        int count2=0;

        for(int end=1;end<arr.size();end++){
            if(arr[end]!= arr[end-1]){
                if(end-start+1 >= k){
                    count2++;
                }
            }
            else{
                start =  end;
            }

            if(end == colors.size()-1){
                count1 = count2;
            }
        }

        return count2-count1;
    }
};