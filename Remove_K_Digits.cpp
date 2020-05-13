//Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

//Note:
//The length of num is less than 10002 and will be ≥ k.
//The given num does not contain any leading zero.

//TC:- O(kn)
//SC:- O(1)

class Solution {
    
public:
    string removeKdigits(string num, int k) {
        int prev = 0;
        num[num.length()] == 0;
        for(int i=0; i<=num.length(); i++){
            if(k==0){
                break;
            }
            int temp = num[i]-'0';
            if(temp < prev){
                num.erase(i-1, 1);
                k--;
                i = -1;
                prev = 0;
                continue;
            }
            prev = temp;
        }
        
        int count = 0;
        for(int i=0; i<num.length(); i++){
            if(num[i] != '0'){
                break;
            }
            count++;
        }
        num.erase(0, count);
        if(num.length() == 0){
            return "0";
        }
        return num;
    }
};
