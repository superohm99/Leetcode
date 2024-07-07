/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **result = NULL;
int *list = NULL;
int k = 0;
int result_size = 0;
int *result_col_size = NULL;


void add_result() {
    result[result_size] = malloc(sizeof(int) * k);
    memcpy(result[result_size], list, sizeof(int) * k);
    result_col_size[result_size] = k;
    result_size++;
}


void backtrack(int *nums, int size, int *checker) {
    int i;

    i = 0;
    if (k == size) {
        printf(" k:%d size:%d ",k, size);
        add_result();
        return ;
    }

    while (i < size) {
        if (checker[i] != 1) {
            checker[i] = 1;
            list[k++] = nums[i];
            backtrack(nums, size, checker);
            k--;
            checker[i] = 0;
        }

        i++;
    }
}


int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int set_num[6];
    int numPer = 1;
    printf("%d",sizeof(numsSize));
    for(int i = 1; i <= numsSize; i++)
    {
        numPer *= i;
    }

    k = 0;
    result_size = 0;
    list = malloc(sizeof(int) * numPer);
    result_col_size = malloc(sizeof(int) * numPer);
    result = malloc(sizeof(int*) * numPer);
    memset(set_num, 0, 6);

    backtrack(nums , numsSize, set_num);
    
    *returnSize = numPer;
    *returnColumnSizes = malloc(sizeof(int) * numPer);
    for (int i = 0; i < numPer; i++) {
        (*returnColumnSizes)[i] = result_col_size[i];
    }

    free(result_col_size);
    free(list);

    return result;
}