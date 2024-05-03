#include <stdio.h>
int min(int a, int b) {
return (a < b) ? a : b;
}int minCoins(int coins[], int m, int V) {
int table[m + 1][V + 1];
for (int i = 0; i <= m; i++)
table[i][0] = 0;
for (int i = 1; i <= V; i++)
table[0][i] = i;
for (int i = 1; i <= m; i++) {
for (int j = 1; j <= V; j++) {
if (coins[i - 1] > j)
table[i][j] = table[i - 1][j];
else
table[i][j] = min(table[i - 1][j], 1 + table[i][j - coins[i - 1]]);
}
}
printf("Capacity/Coins\t\n");
printf("\t\t");
for (int i = 0; i <= V; i++) {
printf("%d\t", i);
}
printf("\n");
for (int i = 1; i <= m; i++) {
printf("%d\t\t", coins[i - 1]);
for (int j = 0; j <= V; j++) {
printf("%d\t", table[i][j]);
}
printf("\n");
}
int i = m, j = V, p = 0;
int sol[m + 1];while (j > 0) {
if (table[i][j] == table[i - 1][j])
i = i - 1;
else {
j = j - coins[i - 1];
sol[p] = coins[i - 1];
p++;
}
}
printf("Coins used: ");
for (int k = 0; k < p; k++) {
printf("%d ", sol[k]);
}
printf("\n");
return table[m][V];
}
int main() {
printf("Vinit Shah C3-2 C183 60004220097\n");
int coins[100], m, V;
printf("Enter the number of coins: ");
scanf("%d", &m);
printf("Enter the coins: ");
for (int i = 0; i < m; i++) {
scanf("%d", &coins[i]);
}
printf("Enter the total amount: ");
scanf("%d", &V);
int minCount = minCoins(coins, m, V);
printf("Minimum number of coins required: %d\n", minCount);return 0;
}
