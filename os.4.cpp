#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], bt[n], wt[n], tat[n];
   
    for(int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(bt[j] < bt[i]) {
                int t = bt[i]; 
                bt[i] = bt[j]; 
                bt[j] = t;

                t = pid[i]; 
                pid[i] = pid[j]; 
                pid[j] = t;
            }
        }
    }
    wt[0] = 0;
    for(int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];
    for(int i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", pid[i], bt[i], wt[i], tat[i]);

    return 0;
}

