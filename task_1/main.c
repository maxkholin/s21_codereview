#include <stdio.h>

int scanMatrix(int N, int Matrix[N][N]);
void printMatrix(int N, int Matrix[N][N]);
void mulMatrix(int N, int MatrixFirst[N][N], int MatrixSecond[N][N],
               int MatrixRes[N][N]);

int main() {
  int N;
  if (scanf("%d", &N) != 1) {
    printf("n/a\n");
    return 0;
  }
  int A[N][N];
  int B[N][N];
  int C[N][N];

  if (scanMatrix(N, A) == 0) {
    return 0;
  }
  if (scanMatrix(N, B) == 0) {
    return 0;
  }

  // printMatrix(N, A);
  // printf("\n");
  // printMatrix(N, B);

  mulMatrix(N, A, B, C);

  printMatrix(N, C);

  return 0;
}

int scanMatrix(int N, int Matrix[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (scanf("%d", &Matrix[i][j]) != 1) {
        printf("n/a\n");
        return 0;
      }
    }
  }
  return 1;
}

void printMatrix(int N, int Matrix[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d", Matrix[i][j]);
      if (j < N - 1) {
        printf(" ");
      }
    }
    if (i < N - 1) {
      printf("\n");
    }
  }
}

void mulMatrix(int N, int MatrixFirst[N][N], int MatrixSecond[N][N],
               int MatrixRes[N][N]) {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      MatrixRes[i][j] = 0;
      for (int k = 0; k < N; k++) {
        MatrixRes[i][j] += MatrixFirst[i][k] * MatrixSecond[k][j];
      }
    }
}