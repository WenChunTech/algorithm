#include"stdio.h"
#include"string.h"
#include"ctype.h"

char* split(char* s, char* p) {
    char* start = s;
    char* end = s + strlen(s) - 1;
    while (strchr(p, *start) && *start) {
        start++;
    }
    while (strchr(p, *end) && end > start) {
        end--;
    }
    *++end = '\0';
    return start;
}

char* rsplit(char* s, char* p) {
    char* end = s + strlen(s) - 1;
    while (strchr(p, *end) && end >= s) {
        end--;
    }
    *++end = '\0';
    return s;
}

int find(char* s, char* p) {
    char* start = s;
    char* end = s + strlen(s) - 1;
    while (strchr(p, *start) && *start) {
        start++;
    }
    while (strchr(p, *end) && end > start) {
        end--;
    }
    *++end = '\0';
    return start;
}

char* strip(char* s, char* p) {
    char* start = s;
    char* end = s + strlen(s) - 1;
    while (strchr(p, *start) && *start) {
        start++;
    }
    while (strchr(p, *end) && end > start) {
        end--;
    }
    *++end = '\0';
    return start;
}

char* rstrip(char* s, char* p) {
    char* end = s + strlen(s) - 1;
    while (strchr(p, *end) && end >= s) {
        end--;
    }
    *++end = '\0';
    return s;
}

char* lstrip(char* s, char* p) {
    char* start = s;
    while (strchr(p, *start) && *start) {
        start++;
    }
    return start;
}

int startswith(char* s, char* p) {
    return strncmp(s, p, strlen(p)) == 0;
}

int endswith(char* s, char* p) {
    int len = strlen(s);
    int plen = strlen(p);
    return strncmp(s + len - plen, p, plen) == 0;
}

int isalnumstr(char* s) {
    while (*s) {
        if (!isalnum(*s)) {
            return 0;
        }
        s++;
    }
    return 1;
}

int isalphastr(char* s) {
    while (*s) {
        if (!isalpha(*s)) {
            return 0;
        }
        s++;
    }
    return 1;
}

int isdigitstr(char* s) {
    while (*s) {
        if (!isdigit(*s)) {
            return 0;
        }
        s++;
    }
    return 1;
}

int islowerstr(char* s) {
    while (*s) {
        if (!islower(*s)) {
            return 0;
        }
        s++;
    }
    return 1;
}

int isupperstr(char* s) {
    while (*s) {
        if (!isupper(*s)) {
            return 0;
        }
        s++;
    }
    return 1;
}


int main() {
    char s[] = "hello world";
    char* p = strip(s, "ld");
    printf("%s\n", p);


    return 0;
}