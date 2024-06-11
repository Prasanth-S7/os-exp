#include <stdio.h>

int main() {
    int n, i, temp;
    int ct[20], at[20], bt[20], pr[20], p[20], wt[20], tat[20];
    float avgTAT, avgWT;

    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    printf("\nEnter Arrival Time, Burst Time, and Priority for each process\n");
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("\nP[%d]\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
    }

    // Bubble sort based on priority (if same priority, sort based on arrival time)
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pr[j] > pr[j + 1] || (pr[j] == pr[j + 1] && at[j] > at[j + 1])) {
                // Swap priority
                int temp = pr[j];
                pr[j] = pr[j + 1];
                pr[j + 1] = temp;

                // Swap burst time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap arrival time
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap process number
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    ct[0] = at[0] + bt[0];
    float totalTAT = 0, totalWT = 0;

    for (int i = 1; i < n; i++) {
        // When process is idle between i and i+1
        temp = 0;
        if (ct[i - 1] < at[i]) {
            temp = at[i] - ct[i - 1];
        }
        ct[i] = ct[i - 1] + bt[i] + temp;
    }

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time");
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        totalTAT += tat[i];
        totalWT += wt[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    avgTAT = totalTAT / n;
    avgWT = totalWT / n;

    printf("\n\nAverage Turnaround Time: %.2f", avgTAT);
    printf("\nAverage Waiting Time: %.2f\n", avgWT);

    return 0;
}
