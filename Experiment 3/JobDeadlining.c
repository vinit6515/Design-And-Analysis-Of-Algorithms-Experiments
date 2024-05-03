#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
int temp = *a;
*a = *b;
*b = temp;
}
int main(){
printf("Vinit Shah C3-2 C183 60004220097\n");
int size,i,j,u = 1,v = 0;
printf("Enter the number of jobs: ");
scanf("%d",&size);
int start[size],finish[size];
printf("Enter the start and finish times for Jobs:\n");
for(i=0;i<size;i++){
printf("Job %d",i+1);
scanf("%d%d",start+i,finish+i);
}
for (i = 0; i <size-1; i++) {
for (j = 0; j <size - i - 1; j++) {
if (finish[j] > finish[j + 1]) {
swap(finish+j, finish+ j + 1);
swap(start+j, start+ j + 1);
}
}
}
for(i=0;i<size;i++){
if(start[i] >= finish[v]){
u++;
v = i;
}
}
printf("Maximum number of non-conflicting tasks is %d",u);
return 0;
} 