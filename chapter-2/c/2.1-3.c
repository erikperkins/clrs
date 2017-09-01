#include <stdio.h>
#include <stdlib.h>

#define VALUE 5

int *vtoi(char **argv, int *argi);

void main(int argc, char** argv) {
  int array[argc - 1];
  vtoi(argv, array);
  int length = sizeof array / sizeof *array;
  int *end = array + length;

  int index = 0;
  int *p = array;
  while (p < end && *p != VALUE) {
    ++index;
    ++p;
  }

  printf("The value %d is at index %d\n", VALUE, *p == VALUE ? index : -1);
}

int *vtoi(char **argv, int *argi) {
  int *d = argi;
  while (*++argv != NULL) {
    *d = atoi(*argv);
    d++;
  }
  return argi;
}
