int lengthOfLongestSubstring(char* s) {
    int len;
    int set_assci[128];
    char *forw;
    char  *ch_forw;
    int count;
    
    len = strlen(s);
    forw = s;
    ch_forw = s;
    count = 0;
    memset(set_assci, 0, sizeof(set_assci));
    while (forw < s + len) {
        if (set_assci[*forw] == 0) {
            set_assci[*forw] = 1;
            forw++;
            if (forw - ch_forw > count) {
                printf(" %c ",*forw);
                printf("ch %c che",*ch_forw);
                count = forw - ch_forw;
            }
        }
        else {
                set_assci[*ch_forw] = 0;
                ch_forw++;
        }
    }
    return count;
}