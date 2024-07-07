int mySqrt(int x) {
    long int result;

    result = 0;    
    while (result * result <= x) {
        result++;
    }
    return result - 1;
}