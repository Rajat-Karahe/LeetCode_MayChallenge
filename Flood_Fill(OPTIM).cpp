//Runtime: 12 ms
//Memory Usage: 13.9 MB
//Better than 98% of submissions

class Solution {
private:
    void dfs(vector<vector<int>>& image, int m, int n, int sr, int sc, int newColor, int oldColor){
        if(sr < 0 || sr >= m || sc < 0 || sc >= n || image[sr][sc] != oldColor){
            return;
        }
        
        image[sr][sc] = newColor;
        dfs(image, m, n, sr-1, sc, newColor, oldColor);
        dfs(image, m, n, sr+1, sc, newColor, oldColor);
        dfs(image, m, n, sr, sc-1, newColor, oldColor);
        dfs(image, m, n, sr, sc+1, newColor, oldColor);
    }
    
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int m = image.size();
        if(m == 0) return image;
        int n = image[0].size();
        if(n == 0) return image;
        
        int oldColor = image[sr][sc];
        
        if(oldColor != newColor){
            dfs(image, m, n, sr, sc, newColor, oldColor);
        }
        
        return image;
    }
};
