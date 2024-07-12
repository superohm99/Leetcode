bool isPalindrome(char * s) {
    char* first = s;
    char* last = s + strlen(s) - 1;

    while (first <= last) {
        if (isalnum(*first) && isalnum(*last)) {
            if (tolower(*first++) != tolower(*last--)) return false;
        }
        else {
            if (!isalnum(*first)) ++first;
            if (!isalnum(*last)) --last;
        }
    }

    return true;
}