#include <stdio.h>
#include <stdlib.h>

int *vtoi(char **argv, int *argi);

int minimum(int *array);

void main(int argc, char **argv) {
  int array[argc - 1];
  vtoi(argv, array);
  int length = sizeof array / sizeof *array;

  for (int i = 0; i < length; i++) {
    int min = array[i];
    int m = i;
    for (int j = i + 1; j < length; j++) {
      if (array[j] < min) {
        min = array[j];
        m = j;
      }
    }
    array[m] = array[i];
    array[i] = min;
  }

  for (int i = 0; i < length; i++) printf("%d\n", array[i]);
}

int *vtoi(char **argv, int *argi) {
  int *d = argi;
  while (*++argv != NULL) {
    *d = atoi(*argv);
    d++;
  }
  return argi;
}

int minimum(int *array) {
  int length = sizeof array / sizeof *array;

  int min = *array;
  for (int i = 0; i < length; i++) {
    min = (array[i] < min) ? array[i] : min;
  }

  return min;
}
