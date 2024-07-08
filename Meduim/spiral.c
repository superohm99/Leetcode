/**
 * Note: The returned array must be malloced, assume caller calls free().
 */




int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m;
    int n;
    int total_area;
    int *result;
    int index = 0;
    int left;
    int right;
    int bottom;
    int top;

    m = matrixSize;
    n = *matrixColSize;
    total_area = m * n;
    *returnSize = total_area;
    result = (int*)malloc(sizeof(int) * total_area);
    left = 0;
    top = 0;
    right = n - 1;
    bottom = m - 1;
    while (index < total_area && top<=bottom && left<=right) {
        
        for(int i = left; i <= right && index < total_area; i++) {
            //left to right
            result[index] = matrix[top][i];
            index++;
        }

        top++;

        for(int i = top; i <= bottom && index < total_area; i++) {
            //top to bottom
            result[index] = matrix[i][right];
            index++;
        }

        right--;
    
    if(top<=bottom){
        for(int i = right; i >= left && index < total_area; i--) {
            //right to left
            result[index] = matrix[bottom][i];
            index++;
        }
    
        bottom--;
    }

    if(left<=right){
        for (int i = bottom; i >= top && index < total_area; i--) {
            //bottom to top
            result[index] = matrix[i][left];
            index++;
        }

        left++;
    }

    }
    // printf("%d", *result);
    return result;
}
