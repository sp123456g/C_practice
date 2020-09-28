void rotate(int** matrix, int matrixSize, int* matrixColSize){

    int temp;
    int min_length;
    int max_length;
    
    for(int i=0;i<*matrixColSize/2;i++){
        
        min_length = i;
        max_length = *matrixColSize-1-i;
        
        for(int s=0,k=min_length;k<max_length;k++,s++){
            temp = matrix[min_length][min_length+s];
            matrix[min_length][min_length+s] = matrix[max_length-s][min_length];
            matrix[max_length-s][min_length] = matrix[max_length][max_length-s];
            matrix[max_length][max_length-s] = matrix[min_length+s][max_length];
            matrix[min_length+s][max_length] = temp;
        }
    }
}
