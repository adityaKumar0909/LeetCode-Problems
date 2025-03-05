class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> freq;
        int count = 0;
        for(int i=0;i<answers.size();i++){
            if(freq[answers[i]] > 0){
                cout<<"inside block 1"<<endl;
                freq[answers[i]]--;
            }
            else{
                cout<<"inside block 2"<<endl;
                freq[answers[i]] = answers[i];
                count += answers[i]+1;
            }
        }

        return count;
        
    }
};