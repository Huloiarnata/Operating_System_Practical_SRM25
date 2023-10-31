#include<stdio.h>
int main(){
    int n, i, j, bt[30], wait_t[30], turnar_t[30], avg_w_t=0, avg_ar_t=0;
    printf("Enter total number of processes\n");
    scanf("%d",&n);
    printf("Enter burst time of processes\n");
    for(i=0;i<n;i++){
        printf("P[%d]",i+1);
        scanf("%d",&bt[i]);
    }
    wait_t[0] = 0;
    for(i=1;i<n;i++){
        wait_t[i] = 0;
        for(j=0;j<i;j++){
            wait_t[i]+=bt[j];
        }
    }
    printf("Process\t\tBurst Time\t\tWaiting_Time\t\tTurn_Around_Time\n");
    for(i=0;i<n;i++){
        turnar_t[i] = bt[i]+wait_t[i];
        avg_w_t += wait_t[i];
        avg_ar_t += turnar_t[i];
        printf("P[%d]\t\t  %d\t\t\t  %d\t\t\t\t  %d\n", i+1,bt[i],wait_t[i],turnar_t[i]);
    }
    avg_ar_t = avg_ar_t/i;
    avg_w_t = avg_w_t/i;
    printf("Average Waiting time : %d\n Average turn around time %d\n",avg_w_t,avg_ar_t);
    return 0;
}