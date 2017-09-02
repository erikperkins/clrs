#include <stdio.h>
#include <stdlib.h>

int *vtoi(char **argv, int *argi);
void mergesort(int *array, int *end);

void main(int argc, char **argv) {
  int array[argc - 1];
  vtoi(argv, array);
  int length = sizeof array / sizeof *array;
  int *end = array + length;

  mergesort(array, end);

  int *a = array;
  while (a < end) {
    printf("%d\n", *a);
    a++;
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

void mergesort(int *array, int *end) {
  int length = end - array;
  int lsize = length / 2;
  int rsize = length - length / 2;
  int left[lsize];
  int right[rsize];
  int *lend = left + lsize;
  int *rend = right + rsize;

  for (int i = 0; i < lsize; i++) left[i] = array[i];
  for (int i = 0; i < rsize; i++) right[i] = array[i + lsize];

  if (lsize > 1) mergesort(left, lend);
  if (rsize > 1) mergesort(right, rend);

  int l = 0, r = 0;
  while (r + l < length) {
    if (l >= lsize) {
      array[r + l] = right[r];
      r++;
      continue;
    }

    if (r >= rsize) {
      array[r + l] = left[l];
      l++;
      continue;
    }

    if (left[l] < right[r]) {
      array[r + l] = left[l];
      l++;
    } else {
      array[r + l] = right[r];
      r++;
    }
  }
}
