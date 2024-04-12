#include <math.h>
#include <stdio.h>

typedef struct Human {
  char firstName[21];
  char lastName[21];
  int height;
} Human;

int scanHuman(Human *human);
int checkHumanHeiht(Human *human, int height);

int main() {
  int N;
  if (scanf("%d", &N) != 1) {
    printf("n/a\n");
    return 0;
  }

  Human humans[N];
  for (int i = 0; i < N; i++) {
    if (!scanHuman(&humans[i])) {
      return 0;
    }
  }

  int H;
  if (scanf("%d", &H) != 1) {
    printf("n/a\n");
    return 0;
  }

  int count = 0;
  for (int i = 0; i < N; i++) {
    if (count > 0 && checkHumanHeiht(&humans[i], H)) {
      printf(", ");
      printf("%s %s", humans[i].firstName, humans[i].lastName);
    } else if (checkHumanHeiht(&humans[i], H)) {
      printf("%s %s", humans[i].firstName, humans[i].lastName);
      count++;
    }
  }

  return 0;
}

int scanHuman(Human *human) {
  scanf("%s", human->firstName);
  scanf("%s", human->lastName);
  if (scanf("%d", &human->height) != 1) {
    printf("n/a\n");
    return 0;
  }
  return 1;
}

int checkHumanHeiht(Human *human, int height) {
  if (human->height >= height) {
    return 1;
  }
  return 0;
}
