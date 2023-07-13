#include "ctype.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char *split(char *s, char *p) {
  char *start = s;
  char *end = s + strlen(s) - 1;
  while (strchr(p, *start) && *start) {
    start++;
  }
  while (strchr(p, *end) && end > start) {
    end--;
  }
  *++end = '\0';
  return start;
}

char *rsplit(char *s, char *p) {
  char *end = s + strlen(s) - 1;
  while (strchr(p, *end) && end >= s) {
    end--;
  }
  *++end = '\0';
  return s;
}

char *find(char *s, char *p) {
  char *start = s;
  char *end = s + strlen(s) - 1;
  while (strchr(p, *start) && *start) {
    start++;
  }
  while (strchr(p, *end) && end > start) {
    end--;
  }
  *++end = '\0';
  return start;
}

char *strip(char *s, char *p) {
  char *start = s;
  char *end = s + strlen(s) - 1;
  while (strchr(p, *start) && *start) {
    start++;
  }
  while (strchr(p, *end) && end > start) {
    end--;
  }
  *++end = '\0';
  return start;
}

char *rstrip(char *s, char *p) {
  char *end = s + strlen(s) - 1;
  while (strchr(p, *end) && end >= s) {
    end--;
  }
  *++end = '\0';
  return s;
}

char *lstrip(char *s, char *p) {
  char *start = s;
  while (strchr(p, *start) && *start) {
    start++;
  }
  return start;
}

int startswith(char *s, char *p) { return strncmp(s, p, strlen(p)) == 0; }

int endswith(char *s, char *p) {
  int len = strlen(s);
  int plen = strlen(p);
  return strncmp(s + len - plen, p, plen) == 0;
}

int isalnumstr(char *s) {
  while (*s) {
    if (!isalnum(*s)) {
      return 0;
    }
    s++;
  }
  return 1;
}

int isalphastr(char *s) {
  while (*s) {
    if (!isalpha(*s)) {
      return 0;
    }
    s++;
  }
  return 1;
}

int isdigitstr(char *s) {
  while (*s) {
    if (!isdigit(*s)) {
      return 0;
    }
    s++;
  }
  return 1;
}

int islowerstr(char *s) {
  while (*s) {
    if (!islower(*s)) {
      return 0;
    }
    s++;
  }
  return 1;
}

int isupperstr(char *s) {
  while (*s) {
    if (!isupper(*s)) {
      return 0;
    }
    s++;
  }
  return 1;
}

int CmpInt(const void *p1, const void *p2) { return *(int *)p1 - *(int *)p2; }

int CmpChar(const void *p1, const void *p2) {
  return *(char *)p1 - *(char *)p2;
}

int CmpStr(const void *p1, const void *p2) {
  return strcmp(*(char **)p1, *(char **)p2);
}

void DropDuplicate(char *str) {
  if (str == NULL) {
    return;
  }
  size_t len = strlen(str);
  if (len < 2) {
    return;
  }
  size_t tail = 1;
  for (size_t i = 1; i < len; ++i) {
    size_t j = 0;
    for (; j < tail; ++j) {
      if (str[i] == str[j]) {
        break;
      }
    }
    if (j == tail) {
      str[tail] = str[i];
      ++tail;
    }
  }
  str[tail] = '\0';
}

void Combination(char *str, size_t len, size_t start) {
  if (start == len) {
    printf("%s\n", str);
    return;
  }
  for (size_t i = start; i < len; ++i) {
    int temp = str[start];
    str[start] = str[i];
    str[i] = temp;
    Combination(str, len, start + 1);
    temp = str[start];
    str[start] = str[i];
    str[i] = temp;
  }
}

int main() {

  char *s = (char *)malloc(sizeof(char) * 10);
  printf("origin strlen(s): %llu\n", strlen(s));

  memset(s, 'i', 12);
  printf("after memset, strlen(s): %llu\n", strlen(s));

  int *i = (int *)malloc(sizeof(int) * 10);
  printf("sizeof(i): %llu\n", sizeof(i));

  // strcpy usage
  char *s1 = (char *)malloc(sizeof(char) * 10);
  char s2[] = {"hello"};

  printf("strlen(s1): %llu\n", strlen(s1));
  printf("sizeof(s1): %llu\n", sizeof(s1));
  printf("strlen(s2): %llu\n", strlen(s2));
  printf("sizeof(s2): %llu\n", sizeof(s2));
  strcpy_s(s1, strlen(s2) + 1, s2);
  // strncpy_s(s1, strlen(s2)+1, s2, 3);
  printf("s1=%s\n", s1);
  printf("*****************************\n");

  char s3[] = {"world"};
  // strstr return pointer
  char *p = strstr(s3, "ld");
  printf("p=%s\n", p);
  // calculate the offset
  printf("%lld\n", p - s3);

  p = strchr(s3, 'o');
  printf("strchr p=%s\n", p);
  printf("strchr offset:%lld\n", p - s3);

  p = strrchr(s3, 'l');
  printf("strrchr p=%s\n", p);
  printf("strrchr offset:%lld\n", p - s3);

  p = strtok(s3, "or");
  while (p) {
    printf("strtok p=%s\n", p);
    p = strtok(NULL, "or");
  }

  printf("after strtok, s3=%s\n", s3);
  int a = strcmp(s3, "world");
  printf("strcmp a=%d\n", a);
  a = strncmp(s3, "world", 1);
  printf("strncmp a=%d\n", a);

  char s4[] = {"hello"};
  memmove(s4 + 1, s4, 1);
  printf("memmove s4=%s\n", s4);

  memcpy(s4, "hello", 5);
  printf("memccpy s4=%s\n", s4);

  // int to binary
  char tmp[10] = {};
  char *conv = itoa(5, tmp, 2);
  printf("itoa to 2: conv=%s\n", conv);

  // int to hex
  conv = itoa(17, tmp, 16);
  printf("itoa to 16: conv=0x%s\n", conv);

  // hex to 10
  int hex = strtol("0x11", NULL, 16);
  printf("strtol: hex=%d\n", hex);
  // binary to 10
  int bin = strtol("101", NULL, 2);
  printf("strtol: bin=%d\n", bin);

  int arr[] = {1, 5, 3, 2, 6};
  int key = 3;
  size_t num = 5;
  int *ele = (int *)lfind(&key, arr, &num, sizeof(int), CmpInt);
  // int *ele = (int *)_lsearch(&key, arr, &num, sizeof(arr[0]), CmpInt);
  if (ele) {
    printf("lsearch found element\n");
  } else {
    printf("lsearch not found element\n");
  }

  char str[] = "hellloooehhoo";
  DropDuplicate(str);
  printf("DropDuplicate: %s\n", str);

  return 0;
}