int singleNumber(int* nums, int numsSize) {
    int number;
    int i;

    i = 0;
    number = 0;
    while (i < numsSize) {
        number = number ^ nums[i];
        printf(" %d ", number);
        i++;
    }

    return number;
}