//In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

//If the town judge exists, then:

//The town judge trusts nobody.
//Everybody (except for the town judge) trusts the town judge.
//There is exactly one person that satisfies properties 1 and 2.
//You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

//If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

Memory :- 72mb, Time :- better than 9% of submissions


class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int, vector<int>> mapp;
        unordered_map<int, vector<int>> reverse;
        
        for(int i=0; i<trust.size(); i++){
            mapp[trust[i][0]].push_back(trust[i][1]);
            reverse[trust[i][1]].push_back(trust[i][0]);
        }
        
        for(int i=1; i<=N; i++){
            if(mapp.count(i) == 0){
                if(reverse[i].size() == N-1){
                    return i;
                }
            }
        }
       
        return -1;
    }
};
 
