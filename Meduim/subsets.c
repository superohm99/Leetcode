/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **result;
    int num_subs;
    int index;

 
    num_subs = 1 << numsSize;
    result = (int **)malloc(sizeof(int*) * num_subs);
    *returnColumnSizes = malloc(num_subs*sizeof(int));
    *returnSize = num_subs;

    for (int i = 0; i < num_subs; i++) {
        result[i] = (int *)malloc(sizeof(int) * numsSize);
        *(*returnColumnSizes+i) = 0;
        index = 0;

        for (int j = 0; j < numsSize; j++) {
            if(i & ( 1 << j)){
            result[i][index++] = nums[j];
            *(*returnColumnSizes+i) += 1 ;
            }
        }

    }

    return result;
}