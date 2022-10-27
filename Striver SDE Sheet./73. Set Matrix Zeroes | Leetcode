// Solution 1
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    //Making the row zero process
                    for(int k=0;k<matrix[i].size();k++){
                        if(matrix[i][k]!=0){
                        matrix[i][k]=1e5;
                        }
                    }
                    //maling the column zero process
                    for(int l=0;l<matrix.size();l++){
                        if(matrix[l][j]!=0){
                        matrix[l][j]=1e5;
                        }
                    }
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==1e5)
                matrix[i][j]=0;
            }
        }
    }
};

// Solution 2 (Better than sol 1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int u= matrix.size();
        int v= matrix[0].size();
        vector<int> A(u,0);
        vector<int> B(v,0);
        for(int i=0;i<u;i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    A[i]=-1;
                    B[j]=-1;
                }
            }
        }
        for(int i=0;i<u;i++){
            for(int j=0;j<matrix[i].size();j++){
                if((A[i]==-1)||(B[j]==-1)){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

//Solution 3 | Best Solution(optimized one)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0) matrix[i][0] = 0;
    }
    }
};
