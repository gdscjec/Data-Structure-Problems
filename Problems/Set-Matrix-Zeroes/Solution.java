class Solution {
    public void setZeroes(int[][] matrix) {
        int m[][]=new int[matrix.length][matrix[0].length];  //This temporary matrix(m) will keep record of matrix, i.e. at what place zero's occurs in matrix
        
      //Traversing matrix
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j]==0){
                  
                  //Marking in temporary matrix (m) the occurence of 0's
                    for(int k=0;k<matrix.length;k++)
                        m[k][j]=1;
                    for(int k=0;k<matrix[0].length;k++)
                        m[i][k]=1;
                }
            }
        }
      
      //Merging matrix with temporary matrix (m)
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(m[i][j]==1)
                    matrix[i][j]=0;
            }
        }
    }
}
