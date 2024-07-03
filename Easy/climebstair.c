int climbStairs(int n) {
    int index[46];
    int i;

    index[0] = 1;
    index[1] = 1;
    index[2] = 2;
    i = 3;
    while (i <= n) {
        index[i] = index[i - 1] + index[i - 2];
        i++;
    }
    return index[n];
}