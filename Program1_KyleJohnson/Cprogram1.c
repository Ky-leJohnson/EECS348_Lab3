#include <stdio.h>
#include <math.h>

#define months 12

void readSalesData(double sales[], int numMonths);
void printMonthlySalesReport(double sales[], int numMonths);
void printMinMaxAvgSales(double sales[], int numMonths);
void printSixMonthMovingAverages(double sales[], int numMonths);

int main(void) {
  double sales[months];

  readSalesData(sales, months);
  printMonthlySalesReport(sales, months);
  printMinMaxAvgSales(sales, months);
  printSixMonthMovingAverages(sales, months);

  return 0;
}

void readSalesData(double sales[], int numMonths) {
  int month;
  FILE *inputFile;

  inputFile = fopen("sales_data.txt", "r");
  if (inputFile == NULL) {
    printf("Error opening file.\n");
    return;
  }

  for (month = 0; month < numMonths; ++month) {
    fscanf(inputFile, "%lf", &sales[month]);
  }

  fclose(inputFile);
}

void printMinMaxAvgSales(double sales[], int numMonths) {
  int i;
  double sum, average, min, max;

  min = max = average = sales[0];
  for (i = 0; i < numMonths; ++i) {
    sum += sales[i];
    if (sales[i] < min) {
      min = sales[i];
    }
    if (sales[i] > max) {
      max = sales[i];
    }
  }
  average = sum / numMonths;

  printf("\nMinimum, Maximum and Average of the Monthly Salaries");
  printf("\nMin: %.2lf", min);
  printf("\nMax: %.2lf", max);
  printf("\nAverage: %.2lf\n", average);
}

void printSixMonthMovingAverages(double sales[], int numMonths) {
  int month, i;
  double moving_average;

  printf("\nSix-month moving averages:\n");
  for (month = 0; month < numMonths - 6; ++month) {
    moving_average = 0.0;
    for (i = 0; i < 6; ++i) {
      moving_average += sales[month + i];
    }
    moving_average /= 6;
    printf("%d: %.2lf\n", month + 1, moving_average);
  }
}

void printMonthlySalesReport(double sales[], int numMonths) {
  int i, j;

  printf("\nMonthly Sales Report (highest to lowest):\n");
  for (i = 0; i < numMonths - 1; ++i) {
    for (j = i + 1; j < numMonths; ++j) {
      if (sales[i] < sales[j]) {
        double temp = sales[i];
        sales[i] = sales[j];
        sales[j] = temp;
        }
      }
    }
  for (i = 0; i < numMonths; ++i) {
    printf("%d: %.2lf\n", i + 1, sales[i]);
  }
  }