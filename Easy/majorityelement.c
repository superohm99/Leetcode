int majorityElement(int* nums, int numsSize) {
    int i;
    int j;
    int max_value;
    int result;
    int set[numsSize][2];

    if (numsSize <= 1)
        return nums[0];
    i = 0;
    max_value = 0;
    result = 0;

    while (i < numsSize) {
        j = 0;
        while (j < 2) {
            set[i][j] = 0;
            j++;
        }
        i++;
    }

    i = 0;
    while (i < numsSize) {
        int num_ch = nums[i];
        j = 0;
        while (j <= i) {
            if (set[j][0] == num_ch) {
                set[j][1] += 1;
                break;
            }
            else if (set[j][0] == 0) {
                set[j][0] = num_ch;
                set[j][1] += 1;
                break;
            }
            j++;
        }
        i++;
    }

    i = 0;
    while (i < numsSize) {
        if (set[i][1] > max_value) {
            result = set[i][0];
            max_value = set[i][1];
        }
        i++;
    }

    

    return result;
}