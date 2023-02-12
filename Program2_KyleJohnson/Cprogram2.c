#include <stdio.h>

int tds, fgs, safeties, tds_and_twos, tds_and_ones;

void calculate_scores(int score) {
  for (tds = 0; tds <= score / 6; tds++) {
    for (tds_and_twos = 0; tds_and_twos <= score / 8; tds_and_twos++) {
      for (tds_and_ones = 0; tds_and_ones <= score / 7; tds_and_ones++) {
        for (fgs = 0; fgs <= score / 3; fgs++) {
          for (safeties = 0; safeties <= score / 2; safeties++) {
            int total = tds * 6 + tds_and_twos * 8 + tds_and_ones * 7 + fgs * 3 + safeties * 2;
            if (total == score) {
              printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Safety\n",
                tds_and_twos, tds_and_ones, tds, fgs, safeties);
            }
          }
        }
      }
    }
  }
}

int main() {
  int score;
  printf("Enter 0 or 1 to STOP\n");
  printf("Enter the NFL score: ");
  scanf("%d", &score);
  while (score > 1) {
    calculate_scores(score);
    printf("Enter the NFL score: ");
    scanf("%d", &score);
  }
  return 0;
}
