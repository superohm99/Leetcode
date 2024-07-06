void resum(int num, int *sum) {
    if (*sum < 10 && *sum != 0 && num == *sum)
        return ;
    while (num != 0) {
        *(sum) += (num % 10); 
        num /= 10;
        printf(" %d ", *sum);
    }
    num = *sum;
    if (*sum >= 10)
        *sum = 0;
    printf(" ddd ");
    resum(num, sum);
}


int addDigits(int num) {
    int sum;
    int *pass;

    sum = 0;
    pass = &sum;

    if (num == 0)
        return 0;

    resum(num, pass);
    return sum;
}