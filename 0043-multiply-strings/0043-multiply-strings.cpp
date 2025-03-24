class Solution {
public:
    string multiply(string num1, string num2) {

        if(num1=="0" || num2=="0") return "0";

        int p = num1.size();
        int q = num2.size();
        vector<int> product(p+q,0);

         //Multiplication part
        for(int i=p-1;i>=0;i--){
            for(int j = q-1;j>=0;j--){
                int prod = (num1[i]-'0') * (num2[j] -'0'); 
                int sum = prod + product[j+i+1];
                product[i+j+1] = sum%10;
                int carry = sum/10;
                product[i+j] += carry;
            }
        } 

        //Find index where leading zeroes end
        int index = -1;
        for(int i=0;i<product.size();i++){
            if(product[i]!=0){
                index = i;
                break;
            }
        }

        // cout<<index<<endl;

        // for(auto x: product ){
        //     cout<<x<<" ";
        // }

        string finalStr="";
        for(int i=index;i<product.size();i++){
            finalStr+=product[i]+'0';
        }

        return finalStr;


        return "hello";
        
    }
};