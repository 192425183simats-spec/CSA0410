#include <stdio.h>

struct Process {
    int pid;
    int bt;      
    int pr;     
    int wt;     
    int tat;     
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &p[i].bt);
        printf("Enter priority for P%d (1 = highest): ", i + 1);
        scanf("%d", &p[i].pr);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].pr > p[j + 1].pr) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    p[0].wt = 0;

    // Calculate waiting time
    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }

    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].wt + p[i].bt;
    }

    printf("\nProcess\tBT\tPR\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].bt, p[i].pr, p[i].wt, p[i].tat);
    }

    return 0;
}

