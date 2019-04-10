#include<stdio.h> 
int waiting_time_cal(int q[][3],int n); 
int Cal_minBurstandArrival(int copyq[][3],int n); 
void show(int r[][3],int ct[],int wt[],int tat[],int n); 
int minBurst(int copyq[][3],int n); 
int main() 
{ 
int i;
int n; 
printf("Enter the number of processes to be processed:\n"); 
scanf("%d",&n); 
int p[n][3]; 
for(i=0;i<n;++i) 
p[i][0]=i+1; 
for(i=0;i<n;++i) 
{ 
printf("Enter Burst Time and Arrival Time for Process %d:", i+1); 
scanf("%d %d",&p[i][1],&p[i][2]); 
if(p[i][2]==0) 
{ 
printf("Arrival Time can't be Zero. Process Discarded!!!!!\n\n"); 
--i; 
n=n-1; 
} 
} 
printf("\n\n"); 
int t=waiting_time_cal(p,n); 
printf("\nTotal time taken by Processor for computation is:%d\n\n",t); 
}
