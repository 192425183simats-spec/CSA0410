#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst[n], waiting[n], tat[n];
    printf("Enter burst times for %d processes:\n", n);
    for(i = 0; i < n; i++) {
        printf("Burst time of P%d: ", i+1);
        scanf("%d", &burst[i]);
    }
    waiting[0] = 0;
    for(i = 1; i < n; i++) {
        waiting[i] = waiting[i-1] + burst[i-1];
    }
    for(i = 0; i < n; i++) {
        tat[i] = waiting[i] + burst[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i+1, burst[i], waiting[i], tat[i]);
    }

    float avgWT = 0, avgTAT = 0;
    for(i = 0; i < n; i++) {
        avgWT += waiting[i];
        avgTAT += tat[i];
    }

    avgWT /= n;
    avgTAT /= n;

    printf("\nAverage Waiting Time: %.2f", avgWT);
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT);

    return 0;
}

