//Given an m x n matrix, return all elements of the matrix in spiral order.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        

        vector<int> ans;

        //matrix[i][j]

        // int rows= sizeof(matrix)/sizeof(matrix[0]);
        int rows = matrix.size();
        int columns= matrix[0].size();

        int top=0;
        int right= columns-1;
        int bottom = rows-1;
        int left =0;

        // int columns= sizeof(matrix)/sizeof(matrix[0][0]);

        //top row 

        while(top<=bottom && left <=right){
        
        //top
        for(int i =left; i<=right; i++){
        ans.push_back(matrix[top][i]);
        }
        top++;

        //right
        for(int i=top; i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;

        //bottom
        if(top<= bottom){
        for(int i= right;i>= left;i-- ){
            ans.push_back(matrix[bottom][i]);
        }
        bottom--;
        }

        //left
        if( left<=right){
        for(int i = bottom; i>=top; i--){
            ans.push_back(matrix[i][left]);
        }
        left++;
        }
        }

        return ans;
    }
};