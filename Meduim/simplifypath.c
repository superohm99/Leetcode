char* simplifyPath(char* path) {
    char *mypath = (char *)malloc(sizeof(char)*(strlen(path) + 1));
    int i;
    int j;
    int checks;
    int k;

    i = 1;
    j = -1;
    mypath[++j] = '/';
    while (i < strlen(path)) {
        if (path[i] == '/') {
            if (mypath[j] == '/') {
                i++;
                continue;
            }
            else
                mypath[++j] = '/';
        }
        else if (path[i] == '.' && path[i - 1] == '/') {
            checks = 0;
            k = i;
            while (i < strlen(path) && path[i] == '.') {
                checks++;
                i++;
            }

            if (checks == 1 && (path[i] == '/' || i == strlen(path))) {
                continue;
            }
            else if (checks == 2 && (path[i] == '/' || i == strlen(path))) {
                if (j > 0)
                    j--;
                while (j > 0 && mypath[j] != '/') {
                    j--;
                }
            }
            else {
                while (k < i) {
                    mypath[++j] = path[k];
                    k++;
                }
                if (i < strlen(path)) {
                    mypath[++j] = path[i];
                }
            }

        }
        else {
            mypath[++j] = path[i];
        }
        i++;
    }

    if (j != 0 && mypath[j] == '/')
        mypath[j] = '\0';
    else
        mypath[++j] = '\0';
    // printf("%s", mypath);
    return mypath;
}