#include<stdio.h>
#include<stdlib.h>
int main(){
printf("Vinit Shah C3-2 C183 600004220097\n");
int size = 7,i,j,temp,M;
float Max_prof = 0,ratio[size], accept[size];
int wt[size], profit[size], desc[size];
printf("Enter the size of knapsack: ");
scanf("%d",&M);
for(i=0;i<size;i++){
accept[size] = 0;
printf("Give weight & nutrition value for fruit %d",i+1);
scanf("%d%d",wt+i,profit+i);
ratio[i] = (float)profit[i]/wt[i];
desc[i] = i;
}
for (i = 0; i < size - 1; i++) {
for (j = 0; j < size - i - 1; j++) {if (ratio[desc[j]] < ratio[desc[j + 1]]) {
temp = desc[j];
desc[j] = desc[j+1];
desc[j+1] = temp;
}
}
}
for(i=0;i<size;i++){
if(M>wt[desc[i]]){
M -= wt[desc[i]];
accept[desc[i]] = 1;
}else{
accept[desc[i]] = (float)M/wt[desc[i]];
M = 0;
break;
}
}
printf("Sr.\tProfit\tWeight\tP/W\t\tContro\n");
for(i=0;i<size;i++){
printf("%d\t%d\t%d\t%f\t%f\n",i+1,profit[i],wt[i],ratio[i],accept[i]);
Max_prof += profit[i]*accept[i];
}
printf("Space left in sack is %d\n",M);
printf("Total profit is %.4f",Max_prof);
return 0;
}