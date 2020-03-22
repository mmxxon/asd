#include <ctype.h>
#include <progbase.h>
#include <progbase/console.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define color1 "\x1B[34m"
#define color2 "\x1B[33m"
#define reset "\x1B[0m"

void count_sort(int size, int array[size]) {
  int max = 0;
  for (int i = 0; i < size; i++) {
    if (array[i] >= max)
      max = array[i];
  }
  max++;
  int c[max];
  int sorted[size];
  for (int i = 0; i < max; i++)
    c[i] = 0;
  for (int i = 0; i < size; i++) {
    c[array[i]]++;
  }
  for (int i = 1; i < max; i++)
    c[i] = c[i] + c[i - 1];
  for (int i = 0; i < size; i++) {
    c[array[i]] = c[array[i]] - 1;
    sorted[c[array[i]]] = array[i];
  }
  for (int i = 0; i < size; i++)
    array[i] = sorted[i];
}
void getarr(int n, int m, int size, int arr[n][m], int array[size]) {
  int k = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] % 10 == 0) {
        array[++k] = arr[i][j];
      }
    }
  }
}
void setarr(int n, int m, int size, int arr[n][m], int array[size]) {
  int k = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] % 10 == 0) {
        arr[i][j] = array[++k];
      }
    }
  }
}
void printarr(int n, int m, int arr[n][m]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] % 10 == 0 && arr[i][j] != 0) {
        printf(color2 "%4i " reset, arr[i][j]);
      } else {
        printf("%4i ", arr[i][j]);
      }
    }
    puts("");
  }
}
int main() {
  system("clear");
  srand(time(0));
  char M[10];
  char N[10];
  printf("Enter M: ");
  fgets(M, 10, stdin);
  int m, n;
  if (isdigit(M[0]))
    m = atoi(M);
  else
    exit(1);
  printf("Enter N: ");
  fgets(N, 10, stdin);
  if (isdigit(N[0]))
    n = atoi(N);
  else
    exit(1);
  if (M <= 0 || N <= 0) {
    puts("N and M must be bigger than 0");
    exit(1);
  }
  int arr[n][m];
  puts("(1)Testcase");
  puts("(2)Random");
  switch (Console_getChar()) {
    case ('1'):
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          arr[i][j] = j * n + i;
        }
      }
      break;
    case ('2'):
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          arr[i][j] = 1 + rand() % 100;
        }
      }
      break;
    default:
      exit(0);
  }
  int size = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] % 10 == 0)
        size++;
    }
  }
  int array[size];
  getarr(n, m, size, arr, array);
  puts(color1 "Before:" reset);
  printarr(n, m, arr);
  count_sort(size, array);
  setarr(n, m, size, arr, array);
  puts(color1 "After:" reset);
  printarr(n, m, arr);
}
