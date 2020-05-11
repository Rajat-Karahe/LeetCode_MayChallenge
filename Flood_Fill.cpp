//An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

//Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

//To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

//At the end, return the modified image.

//Solution was better than 93% of submissions
//This is a problem of Graphs DFS

class Solution {
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int currentColor = image[sr][sc];
        if(image[sr][sc] == newColor){
            return image;
        }
        
        image[sr][sc] = newColor;
        
        if(sr-1 >= 0 && image[sr-1][sc] == currentColor){
            image = floodFill(image, sr-1, sc, newColor);
        }
        if(sr+1 < image.size() && image[sr+1][sc] == currentColor){
            image = floodFill(image, sr+1, sc, newColor);
        }
        if(sc-1 >= 0 && image[sr][sc-1] == currentColor){
            image = floodFill(image, sr, sc-1, newColor);
        }
        if(sc+1 < image[0].size() && image[sr][sc+1] == currentColor){
            image = floodFill(image, sr, sc+1, newColor);
        }
        
        return image;
    }
};
