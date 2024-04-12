#include <math.h>
#include <stdio.h>

int main() {
  const int DENSITY = 21500;
  double radius;
  if (scanf("%lf", &radius) != 1) {
    printf("n/a\n");
    return 0;
  }
  double volume = (4. / 3) * M_PI * pow(radius, 3);
  double weight = DENSITY * volume;

  printf("%.0lf", weight);

  return 0;
}
