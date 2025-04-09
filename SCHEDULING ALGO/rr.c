#include <stdio.h>

void main() {
    int n, tq, i, total_time = 0, remaining;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n], pid[n], remaining_bt[n];

    for (i = 0; i < n; i++) {
        printf("Enter Process ID and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &pid[i], &bt[i]);
        remaining_bt[i] = bt[i]; // Copy burst time for processing
        wt[i] = tat[i] = 0; // Initialize waiting & turnaround times
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    remaining = n; // Number of remaining processes

    int gantt_pid[100], gantt_time[100], index = 0; // To store Gantt Chart entries

    i = 0; 
    gantt_time[index++] = 0; // Start time
    while (remaining > 0) { 
        if (remaining_bt[i] > 0) { 
            gantt_pid[index - 1] = pid[i]; // Store process ID in Gantt chart

            if (remaining_bt[i] > tq) {
                total_time += tq;
                remaining_bt[i] -= tq;
            } else { 
                total_time += remaining_bt[i]; 
                tat[i] = total_time; // Completion time
                wt[i] = tat[i] - bt[i]; // Waiting time
                remaining_bt[i] = 0; 
                remaining--; // Process finished
            }

            gantt_time[index++] = total_time; // Store time in Gantt chart
        }
        i = (i + 1) % n; // Move in round-robin order
    }

    // Print Gantt Chart
    printf("\nGANTT CHART:\n ");
    for (i = 0; i < index - 1; i++) {
        printf("--------");
    }
    printf("\n|");
    for (i = 0; i < index - 1; i++) {
        printf("  P%d  |", gantt_pid[i]);
    }
    printf("\n ");
    for (i = 0; i < index - 1; i++) {
        printf("--------");
    }

    printf("\n");
    for (i = 0; i < index; i++) {
        printf("%d\t", gantt_time[i]);
    }
    printf("\n");

    // Print process details
    float avgwt = 0, avgtat = 0;
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tat[i]);
        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f\n", avgwt / n);
    printf("Average Turnaround Time: %.2f\n", avgtat / n);
}
