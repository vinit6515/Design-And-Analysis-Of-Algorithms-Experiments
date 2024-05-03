#include<stdio.h>
#include<stdlib.h>
int max;
int min;
int B[] = {4,5,46,2,6,55,26};
void minmax_DivCon(int A[], int i, int j)
{
int mid;
if (i == j) {
max = (A[i] > max) ? A[i] : max;
min = (A[i] < min) ? A[i] : min;
return;
}
if (i == j - 1) {
if (A[i] < A[j]) {
min = (A[i] < min) ? A[i] : min;
max = (A[j] > max) ? A[j] : max;
} else {
min = (A[j] < min) ? A[j] : min;
max = (A[i] > max) ? A[i] : max;
}
return;
}
mid = (i + j) / 2;
minmax_DivCon(A, i, mid);
minmax_DivCon(A, mid + 1, j);
}
void minmax_naive(int A[], int size){
if (size == 1) {
min = A[0];
max = A[0];
return;
}
min = A[0];
max = A[0];
for (int i = 1; i < size; i++) {
if (A[i] < min)
min = A[i];
if (A[i] > max)
max = A[i];
}
}
int main(){
printf("Vinit Shah C3-2 C183 600004220097\n");
max = B[0];
min = B[6];
minmax_DivCon(B, 0, 6);
printf("From: [4, 5, 46, 2, 6, 55, 26]\n");
printf("Maximum is %d\nMinimum is %d",max,min);
return 0;
}