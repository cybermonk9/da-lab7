#include <stdio.h>
void discreteKnapsack(int array[][2], int n, int max_qty) {
int i, j = 0;
float sum = 0, max;
int m = max_qty;
printf("DISCRETE KNAPSACK GREEDY SOLUTION\n");
while (m >= 0) {
max = 0;
for (i = 0; i < n; i++) {
if (((float)array[i][1]) / (float)array[i][0] > max) {
max = (((float)array[i][1]) / (float)array[i][0]);
j = i;
}
}
if (array[j][0] > m) {
printf("Quantity of item %d added is %d\n", (j + 1), m);
sum += m * max;
m = -1;
} else {
printf("Quantity of item %d added is %d\n", (j + 1), array[j][0]);
m -= array[j][0];
sum += (float)array[j][1];
array[j][1] = 0;
}
}
printf("Total profit for DISCRETE KNAPSACK: %.2f\n\n", sum);
}
void continuousKnapsack(int array[][2], int n, int max_qty) {
int i, j;
float sum = 0;
printf("CONTINUOUS KNAPSACK GREEDY SOLUTION\n");
for (i = 0; i < n; i++) {
if (max_qty >= array[i][0]) {
printf("Quantity of item %d added is %d\n", (i + 1), array[i][0]);
sum += array[i][1];
max_qty -= array[i][0];
} else {
float fraction = (float)max_qty / array[i][0];
printf("Quantity of item %d added is %.2f (fractional)\n", (i + 1), fraction);
sum += fraction * array[i][1];
break;
}
}
printf("Total profit for CONTINUOUS KNAPSACK: %.2f\n\n", sum);
}
int main() {
int n, max_qty;
int i;
printf("Enter the number of elements: ");
scanf("%d", &n);
int array[20][2];
printf("Enter the weight and value of each item:\n");
for (i = 0; i < n; i++) {
printf("Weight of item %d: ", (i + 1));
scanf("%d", &array[i][0]);
printf("Value of item %d: ", (i + 1));
scanf("%d", &array[i][1]);
}
printf("Enter the maximum value of knapsack: ");
scanf("%d", &max_qty);
discreteKnapsack(array, n, max_qty);
continuousKnapsack(array, n, max_qty);
return 0;
}
