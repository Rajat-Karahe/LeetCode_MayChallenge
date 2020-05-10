class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int, int> mapp;
        unordered_map<int, int> reverse;
        
        for(int i=0; i<trust.size(); i++){
            mapp[trust[i][0]] += 1;
            reverse[trust[i][1]] += 1;
        }
        
        for(int i=1; i<=N; i++){
            if(mapp.count(i) == 0){
                if(reverse[i] == N-1){
                    return i;
                }
            }
        }
       
        return -1;
    }
};
