#include <stdio.h>
#include <limits.h>
#include <math.h>
#define MAX 9999
int n = 4;int distan[20][20] = {
{ 0, 12, 18, 24 },
{ 12, 0, 36, 28 },
{ 18, 36, 0, 32 },
{ 24, 28, 32, 0 }};
int DP[16][4];
int TSP(int mark, int position) {
int completed_visit = pow(2, n) - 1;
if (mark == completed_visit) {
return distan[position][0];
}
if (DP[mark][position] != -1) {
return DP[mark][position];
}
int answer = MAX;
for (int city = 0; city < n; city++) {
if ((mark & (int)pow(2, city)) == 0) {
int newAnswer = distan[position][city] + TSP(mark | (int)pow(2, city), city);
answer = (answer < newAnswer) ? answer : newAnswer;
}
}
return DP[mark][position] = answer;
}
void printPath(int mark, int position) {
int completed_visit = pow(2, n) - 1;
if (mark == completed_visit) {
printf("%d ", position + 1);
return;
}int nextMark, city;
int minDist = MAX;
for (city = 0; city < n; city++) {
if ((mark & (int)pow(2, city)) == 0) {
int newMark = mark | (int)pow(2, city);
int newDist = distan[position][city] + TSP(newMark, city);
if (newDist == DP[mark][position]) {
nextMark = newMark;
break;
}
}
}
printf("%d ", position + 1);
printPath(nextMark, city);
}
int main() {
printf("Vinit Shah C3-2 C183 60004220097\n");
for (int i = 0; i < pow(2, n); i++) {
for (int j = 0; j < n; j++) {
DP[i][j] = -1;
}
}
printf("Minimum Distance Travelled -> %d\n", TSP(1, 0));
printf("Shortest Path Travelled -> ");
printPath(1, 0);
printf("1");
return 0;
}