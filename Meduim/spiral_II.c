/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int **result;
    int num;
    int index;
    int total_area;
    int left;
    int top;
    int right;
    int bottom;


    num = 1;
    index = 0;
    total_area = n * n;
    left = 0;
    top = 0;
    right = n - 1;
    bottom = n - 1;
    result = (int **)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        result[i] = (int *)malloc(sizeof(int) * n);
    }

    while (index < total_area ) {

        for (int i = left; i <= right && index < total_area; i++) {
            result[top][i] = num;
            index++;
            num++;          
        }
        top++;

        for (int i = top; i <= bottom && index < total_area; i++) {
            result[i][right] = num;
            index++;
            num++;
        }

        right--;
        
        if (top <= bottom) {
            for (int i = right; i >= left && index < total_area; i--) {
                result[bottom][i] = num;
                index++;
                num++;
            }

            bottom--;
        } 

        if (left <= right) {
            for (int i = bottom; i >= top && index < total_area; i--) {
                result[i][left] = num;
                index++;
                num++;
            }

            left++;
        } 
        

    }

    *returnSize = n;
    *returnColumnSizes = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
    }

    return result;
}   