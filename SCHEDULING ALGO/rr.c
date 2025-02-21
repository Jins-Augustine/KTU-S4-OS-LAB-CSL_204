#include <stdio.h>

struct process {
    int id, Bt, tBt, Wt, Tat;
} p[20];

// Structure to store Gantt chart entries
struct gantt_entry {
    int process_id;
    int start_time;
    int end_time;
} gantt[100];  // Assuming maximum 100 time slots

int main() {
    int i, n, tq;
    int x = 0, y = 0;  // x = current time, y = completed processes
    int gantt_size = 0;  // Track number of entries in Gantt chart
    float avgwt = 0, avgtat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("\nEnter the Process ID and Burst Time of P-%d: ", i + 1);
        scanf("%d%d", &p[i].id, &p[i].Bt);
        p[i].tBt = p[i].Bt;
        p[i].Wt = 0;
        p[i].Tat = 0;
    }
    
    printf("Enter the Time Quantum: ");
    scanf("%d", &tq);

    i = 0;  // Current process index
    while (y < n) { // Continue until all processes are completed
        if (p[i].Bt > 0) {
            // Store start time for Gantt chart
            gantt[gantt_size].process_id = p[i].id;
            gantt[gantt_size].start_time = x;

            if (p[i].Bt > tq) {
                p[i].Bt -= tq;
                x += tq;
            } else {
                x += p[i].Bt;
                p[i].Bt = 0;
                p[i].Tat = x;  // Completion time
                p[i].Wt = p[i].Tat - p[i].tBt; // Waiting time
                y++;  // Process completed
            }

            // Store end time for Gantt chart
            gantt[gantt_size].end_time = x;
            gantt_size++;
        }
        
        i = (i + 1) % n;  // Move to the next process in a circular manner
    }

    // Print process details
    printf("\nPROCESS ID\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    printf("----------------------------------------------------------\n");
    
    for (i = 0; i < n; i++) {
        printf("%-10d\t%-10d\t%-12d\t%-15d\n", 
               p[i].id, p[i].tBt, p[i].Wt, p[i].Tat);
        avgwt += p[i].Wt;
        avgtat += p[i].Tat;
    }
    
    printf("\nAVERAGE WAITING TIME: %.2f", avgwt / n);
    printf("\nAVERAGE TURNAROUND TIME: %.2f\n", avgtat / n);

    // Print Gantt Chart
    printf("\nGANTT CHART\n");
    printf("------------\n\n");

    // Print upper border
    printf(" ");
    for (i = 0; i < gantt_size; i++) {
        printf("-----");
    }
    printf("\n|");

    // Print process IDs in the Gantt chart
    for (i = 0; i < gantt_size; i++) {
        printf(" P%d |", gantt[i].process_id);
    }

    // Print lower border
    printf("\n ");
    for (i = 0; i < gantt_size; i++) {
        printf("-----");
    }

    // Print timeline
    printf("\n%d", gantt[0].start_time);
    for (i = 0; i < gantt_size; i++) {
        printf("    %d", gantt[i].end_time);
    }
    printf("\n");

    return 0;
}
