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


void backtrack(int *candidate, int size, int target, int start) {
    int i;

    i = start;
    if (target == 0) {
        add_result();
        return;
    }

    while (i < size) {
        if (candidate[i] <= target) {
            list[k++] = candidate[i];

            backtrack(candidate, size, target - candidate[i], i);

            k--;
        }
        i++;
    }
}



int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {

    k = 0;
    result_size = 0;
    list = malloc(sizeof(int) * 150);
    result_col_size = malloc(sizeof(int) * 150);
    result = malloc(sizeof(int*) * 150);

    backtrack(candidates, candidatesSize, target, 0);

    *returnSize = result_size;
    *returnColumnSizes = malloc(sizeof(int) * result_size);
    for (int i = 0; i < result_size; i++) {
        (*returnColumnSizes)[i] = result_col_size[i];
    }

    free(result_col_size);
    free(list);

    return result;
}