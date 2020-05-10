// Memory :- 60mb
// Time :- better than 33% of submissions

static int x = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> forward(N+1, 0);
        vector<int> backward(N+1, 0);
        
        int length = trust.size();
        for(int i=0; i<length; i++){
            int first = trust[i][0];
            int second = trust[i][1];
            forward[first]++;
            backward[second]++;
        }
        
        int count = 0;
        int ans = -1;
        for(int i=1; i<=N; i++){
            if(forward[i] == 0 && backward[i] == N-1){
                count++;
                ans = i;
            }
        }
       
        if(count > 1){
            return -1;
        }
        
        return ans;
    }
};
