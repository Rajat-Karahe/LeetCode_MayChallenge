class Solution {
    int kindane(vector<int>&A){
        int n = A.size();
        int local_max = 0;
        int global_max = INT_MIN;
        
        for(int i=0; i<n; i++){
            local_max = max(A[i], A[i]+local_max);
            
            if(local_max >  global_max){
                global_max = local_max;
            }
        }
        
        return global_max;
    }
    
public:
    int maxSubarraySumCircular(vector<int>& A) {
        
        int kindan_max = kindane(A);
        int max_wrap=0, i;
        int n = A.size();
        for(i=0; i<n; i++){
            max_wrap += A[i];
            A[i] = -A[i];
        }
        max_wrap = max_wrap+kindane(A);
        if(max_wrap == 0){
            return kindan_max;
        }
        return max(max_wrap, kindan_max);
    }
};
