#include <stdio.h>
#include <stdlib.h>

void main(int argc, char **argv) {
  char *a = *++argv;
  char *b = *++argv;

  int length = 0;
  char *c = a;
  while (*c++ != '\0') length++;
  char sum[length + 1];

  char carry = '0';
  for (int i = length - 1; i >= 0; i--) {
    int j = i + 1;
    if (a[i] == b[i]) {
      sum[j] = (carry == '0') ? '0' : '1';
      carry = (a[i] == '0') ? '0' : '1';
    } else {
      sum[j] = (carry == '0') ? '1' : '0';
      carry = (carry == '0') ? '0' : '1';
    }
  }
  sum[0] = carry;

  printf("Sum: %s\n", sum);
}
