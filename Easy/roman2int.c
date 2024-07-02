int romanToInt(char* s) {
    int curv;
    int prev;
    int sum;
    int len;

    curv = 0;
    prev = 0;
    sum = 0;
    len = strlen(s) - 1;
    while (len >= 0) {
        if (s[len] == 'I')
            curv = 1;
        else if (s[len] == 'V')
            curv = 5;
        else if (s[len] == 'X')
            curv = 10;
        else if (s[len] == 'L')
            curv = 50;
        else if (s[len] == 'C')
            curv = 100;
        else if (s[len] == 'D')
            curv = 500;
        else if (s[len] == 'M')
            curv = 1000;
        if (curv < prev)
            sum -= curv;
        else
            sum += curv;
        prev = curv;
        len--;
    }

    return sum;
}