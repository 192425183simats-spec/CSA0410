#include <stdio.h>

int main() {
    int n, q;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rem[n], ct[n];
    for (int i=0; i<n; i++) {
        printf("Enter burst time of P%d: ", i+1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
        ct[i] = 0;
    }

    printf("Enter time quantum: ");
    scanf("%d", &q);

    int time = 0;
    while (1) {
        int done = 1;
        for (int i=0; i<n; i++) {
            if (rem[i] > 0) {
                done = 0;
                if (rem[i] > q) {
                    time += q;
                    rem[i] -= q;
                } else {
                    time += rem[i];
                    rem[i] = 0;
                    ct[i] = time;
                }
            }
        }
        if (done) break;
    }

    printf("\nP\tBT\tCT\tTAT\tWT\n");
    float totalTAT = 0, totalWT = 0;

    for (int i=0; i<n; i++) {
        int tat = ct[i];
        int wt = tat - bt[i];
        totalTAT += tat;
        totalWT += wt;
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, bt[i], ct[i], tat, wt);
    }

    printf("Average TAT = %.2f\n", totalTAT/n);
    printf("Average WT = %.2f\n", totalWT/n);

    return 0;
}

