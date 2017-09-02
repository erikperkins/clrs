#include <stdio.h>
#include <stdlib.h>

int *vtoi(char **argv, int *argi);

void main(int argc, char **argv) {
  int array[argc - 1];
  vtoi(argv, array);
  int length = sizeof array / sizeof *array;
  int *end = array + length;

  int *a = array;
  while (++a < end) {
    int key = *a;
    int *b = a;
    while (--b >= array && *b > key) {
      *(b + 1) = *b;
    }
    *(b + 1) = key;
  }

  a = array;
  while (a < end) {
    printf("%d\n", *a);
    ++a;
  }
}

int *vtoi(char **argv, int *argi) {
  int *d = argi;
  while (*++argv != NULL) {
    *d = atoi(*argv);
    d++;
  }
  return argi;
}
