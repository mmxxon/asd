#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void coutMatrix(size_t lI, size_t lJ, int arr[lI][lJ]);
void fillMatrix(size_t lI, size_t lJ, int arr[lI][lJ]);
void fillMatrixR(size_t lI, size_t lJ, int arr[lI][lJ]);
int goThroughMatrix(int lI, int lJ, int arr[lI][lJ], int searched);
int main() {
  srand(time(0));
  int n = 0;
  int m = 0;
  int k = 0;
  int res = 0;
  int key = 0;
  printf("Enter N:");
  scanf("%i", &n);
  printf("Enter M:");
  scanf("%i", &m);
  size_t lI = n;
  size_t lJ = m;
  int arrControl[lI][lJ];
  int arr[lI][lJ];
  if (m % 2 != 0 || n < 0) {
    return 0;
  }

  do {
    fflush(stdin);
    printf("\nEnter 1 to see random matrix\nEnter 2 to see control "
           "matrix\nEnter 3 to clear console\nEnter 4 to quit\n");
    scanf("%i", &key);
    if (key == 1) {
      while (true) {
        fflush(stdin);
        fillMatrixR(lI, lJ, arr);
        coutMatrix(lI, lJ, arr);
        printf("\nEnter 1 to random new matrix\nEnter 2 to search for "
               "element\nEnter 3 to quit\n");
        scanf("%i", &key);
        if (key == 1) {

        } else if (key == 2) {
          printf("\nEnter searched element\n");
          scanf("%i", &k);
          res = goThroughMatrix(lI, lJ, arrControl, k);
          if (res == 0) {
            printf("Can`t found such element");
          } else {
          }
        } else if (key == 3) {
          break;
        }
      }

    } else if (key == 2) {
      while (true) {
        fflush(stdin);
        fillMatrix(lI, lJ, arrControl);
        coutMatrix(lI, lJ, arrControl);
        printf("\nEnter 1 to search for element\nEnter 2 to quit");
        scanf("%i", &key);
        if (key == 1) {
          printf("\nEnter searched element\n");
          scanf("%i", &k);
          res = goThroughMatrix(lI, lJ, arrControl, k);
          if (res == 0) {
            printf("Can`t found such element");
          } else {
          }

        } else if (key == 2) {
          break;
        }
      }

    } else if (key == 3) {
      system("clear");
    } else if (key == 4) {
      return 0;
    }
  } while (!strchr("12345", key));
  return 0;
}
void fillMatrix(size_t lI, size_t lJ, int arr[lI][lJ]) {
  int count = 0;
  for (int i = 0; i < lI; i++) {
    for (int j = 0; j < lJ; j++) {
      arr[i][j] = count;
      count++;
    }
  }
}
void coutMatrix(size_t lI, size_t lJ, int arr[lI][lJ]) {
  for (int i = 0; i < lI; i++) {
    for (int j = 0; j < lJ; j++) {
      printf("%3i ", arr[i][j]);
    }
    printf("\n");
  }
}
void fillMatrixR(size_t lI, size_t lJ, int arr[lI][lJ]) {
  int count = 0;
  for (int i = 0; i < lI; i++) {
    for (int j = 0; j < lJ; j++) {
      arr[i][j] = rand() % (RAND_MAX - 1) + 0;
      count++;
    }
  }
}
int goThroughMatrix(int lI, int lJ, int arr[lI][lJ], int searched) {
  int i, j;
  int a = -1;
  int b = -1;
  int count = 0;
  int dir = 0;
  i = 0;
  j = 0;
  dir = 1;
  int rofl = lJ / 2;
  for (count = 0; count < lI * rofl; count++) {
    if (arr[i][j] == searched) {
      a = i;
      b = j;
    }
    printf("%i  ", arr[i][j]);
    i -= dir;
    j += dir;
    if (i == lI) {
      i--;
      j += 2;
      dir = -dir;
    }
    if (j == rofl) {

      j--;
      i += 2;
      dir = -dir;
    }
    if (i == -1) {
      i++;
      dir = -dir;
    }
    if (j == -1) {
      j++;
      dir = -dir;
    }
  }
  printf("\n\n");
  i = lI - 1;
  j = lJ / 2;
  dir = 1;
  for (int ct = 0; ct < lJ / 2 * rofl; ct++) {
    if (arr[i][j] == searched) {
      a = i;
      b = j;
    }
    printf("%i  ", arr[i][j]);
    i -= dir;
    if (i == -1) {
      i++;
      dir = -dir;
      j++;
    } else if (i >= lI) {
      i = lI - 1;
      dir = -dir;
      j++;
    } else {
    }
  }
  if (a != -1) {
    printf("\nSearched: index(%i,%i)\n", a, b);
    return 1;
  } else {
    return 0;
  }
}