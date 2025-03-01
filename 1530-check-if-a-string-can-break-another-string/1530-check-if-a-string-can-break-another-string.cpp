class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {

        sort(s2.begin(),s2.end());
        sort(s1.begin(),s1.end());


        cout<<s1<<endl<<s2<<endl;

        bool doesS2broke=true;
        bool doesS1broke=true;


        for(int i=0;i<s1.length();i++){
            if(s1[i]>s2[i]) doesS2broke = false;
        }

        for(int i=0;i<s1.length();i++){
            if(s1[i]<s2[i]) doesS1broke = false;
        }

        if(doesS2broke || doesS1broke) return true;
        else return false;

    }
};