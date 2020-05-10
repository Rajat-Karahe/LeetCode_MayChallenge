// Almost same as OPtim

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> forward(N+1, 0);
        vector<int> backward(N+1, 0);
        
        for(int i=0; i<trust.size(); i++){
            forward[trust[i][0]] += 1;
            backward[trust[i][1]] += 1;
        }
        
        for(int i=1; i<=N; i++){
            if(forward[i] == 0){
                if(backward[i] == N-1){
                    return i;
                }
            }
        }
       
        return -1;
    }
};
