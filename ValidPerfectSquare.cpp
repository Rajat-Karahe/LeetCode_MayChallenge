//Given a positive integer num, write a function which returns True if num is a perfect square else False.

//Note: Do not use any built-in library function such as sqrt.

class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num == 1 || num == 2){
            return true;
        }
        long int first = log2(num);
        
        for(long int i=first; i<=num/2; i++){
            long int temp = i*i;
            if(temp == num){
                return true;
            }
            if(temp > num){
                break;
            }
        }
        
        return false;
    }
};
