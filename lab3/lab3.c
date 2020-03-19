#include <ctype.h>
#include <progbase.h>
#include <progbase/console.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define OUT "\x1B[1;36m"
#define IN "\x1B[1;37;44m"
#define ERR "\x1B[5;31m"

#define DIAG1 "\x1B[1;37;41m"
#define DIAG2 "\x1B[1;37;45m"
#define CENTRAL "\x1B[4;32;47m"
#define WHITE "\x1B[0;30;47m"
#define BR "\x1B[1;31m"
#define RESET "\x1B[0m"

void RM(size_t I, size_t J, int arr[I][J]) {
  printf(BR "  INPUT MATRIX:\n" WHITE);
  for (int i = 0; i < I; i++) {
    for (int j = 0; j < J; j++) {
      arr[i][j] = rand() % 999;
      if (i == j && i + j == J - 1) {
        printf(WHITE " \x1B[1m" CENTRAL "%4i" WHITE, arr[i][j]);
      } else if (i == j) {
        printf(WHITE " " DIAG1 "%4i" WHITE, arr[i][j]);
      } else if (i + j == J - 1) {
        printf(WHITE " " DIAG2 "%4i" WHITE, arr[i][j]);
      } else {
        printf(WHITE " %4i" WHITE, arr[i][j]);
      }
    }
    puts("");
  }
  puts("");
  int D1[I], D2[I], min1, min2;
  int counter = J - 1;
  for (int i = 0; i < I; i++, counter--) {
    if (counter != i) {
      D1[i] = arr[i][i];
      D2[i] = arr[i][counter];
    }
  }
  for (int i = 0; i < I - 1; i++) {
    min1 = i, min2 = i;
    for (int j = i + 1; j < J; j++) {
      if (D1[j] < D1[min1]) {
        min1 = j;
      }
      if (D2[j] < D2[min2]) {
        min2 = j;
      }
    }
    if (min1 != i) {
			int tmp;
      tmp = D1[i];
      D1[i] = D1[min1];
      D1[min1] = tmp;
    }
    if (min2 != i) {
			int tmp;
      tmp = D2[i];
      D2[i] = D2[min1];
      D2[min1] = tmp;
    }
  }
  printf(BR "  OUTPUT MATRIX:\n" WHITE);
  int counter1 = 0, counter2 = 0;
  for (int i = 0; i < I; i++) {
    for (int j = 0; j < J; j++) {
      if (i == j && i + j == J - 1) {
      } else if (i == j) {
        arr[i][j] = D1[counter1];
				counter1++;
      } else if (i + j == J - 1) {
        arr[i][j] = D2[counter2];
				counter2++;
      }
      if (i == j && i + j == J - 1) {
        printf(WHITE " \x1B[1m" CENTRAL "%4i" WHITE, arr[i][j]);
      } else if (i == j) {
        printf(WHITE " " DIAG1 "%4i" WHITE, arr[i][j]);
      } else if (i + j == J - 1) {
        printf(WHITE " " DIAG2 "%4i" WHITE, arr[i][j]);
      } else {
        printf(WHITE " %4i" WHITE, arr[i][j]);
      }
    }
    puts("");
  }
}
// void TM(size_t I, size_t J, int arr[I][J]);

int main() {
  char key;
  do {
    int n, m;
    Console_clear();
    do {
      printf(RESET OUT "Enter Height: " IN);
      scanf("%i", &n);
      if (n <= 0) {
        puts(ERR "Height must be bigger than 0" RESET);
      }
    } while (n <= 0);
    do {
      printf(RESET OUT "Enter Width:  " IN);
      scanf("%i", &m);
      if (m <= 0) {
        puts(ERR "Width must be bigger than 0" RESET);
      }
    } while (m <= 0);
    puts("\n");
    size_t I = n;
    size_t J = m;
    int arr[I][J];
    int z = 1;
    do {
      while (z == 1) {
        printf(RESET OUT "| W = %i | H = %i |\n\n" RESET, J, I);
        printf(DIAG2 "1 - RANDOM\n" RESET);
        printf(DIAG2 "2 - TEST  \n" RESET);
        printf(DIAG2 "3 - REPEAT\n" RESET);
        printf(DIAG2 "4 - EXIT  \n" RESET);
        z = 0;
      }
      key = Console_getChar();
      switch (key) {
      case '1':
        Console_clear();
        RM(I, J, arr);
        z = 1;
        break;
      case '2':
        Console_clear();
        // TM(I, J, arr);
        z = 1;
        break;
      case '3':
        break;
      case '4':
      case '\n':
        Console_clear();
        exit(0);
        break;
      }
    } while (key != '3');
  } while (1);
}