#include<stdio.h>  // Standard input output header file

int main(){
    // Declaration of variables
    // avail[] -> Available resources
    // alloc[][] -> Allocated resources matrix
    // max[][] -> Maximum resources required by each process
    // need[][] -> Resources still needed (calculated later)
    // maxres[] -> Total maximum resources in the system
    int avail[10], alloc[10][10], max[10][10], need[10][10], maxres[10];

    int m, n, i, j, k, sum;  // m = no of resources, n = no of processes

    // Input number of processes and resources
    printf("\nEnter the number of processes and the number of resources: ");
    scanf("%d%d", &n, &m);

    // Input the maximum instances of each resource in the system
    printf("\nEnter the maximum instances of resources:\n");
    for(j=0; j<m; j++){
        scanf("%d", &maxres[j]);  // maxres[j] stores max available of resource j
        avail[j] = maxres[j];     // Initialize available resources with max values
    }

    // Input Allocated Resources Matrix
    printf("\nEnter the Allocated Matrix:\n");
    for(i=0; i<n; i++){ // Loop for processes
        for(j=0; j<m; j++){ // Loop for resources
            scanf("%d", &alloc[i][j]);  // alloc[i][j] means how many resource j allocated to process i
        }
    }

    // Input Maximum Requirement Matrix
    printf("\nEnter the Max Matrix:\n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf("%d", &max[i][j]); // max[i][j] means max resources j needed by process i
            need[i][j] = max[i][j] - alloc[i][j]; // need = max - alloc (still required resources)
        }
    }

    // Print Need Matrix
    printf("\nThe Need Matrix is:\n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%d ", need[i][j]);  // Display remaining need of each process
        }
        printf("\n");
    }

    // Calculate Available Resources after allocation
    // Initially we stored max resources in avail[] 
    for(j=0; j<m; j++){
        sum = 0;
        for(i=0; i<n; i++){
            sum += alloc[i][j]; // Sum of allocated resource j to all processes
        }
        avail[j] -= sum; // Available resources = max - allocated
    }

    int finish[10], safeseq[10], ind=0;

    // Initialize finish[] array to 0 (0 means process is not yet finished)
    for(k=0; k<n; k++){
        finish[k] = 0;
    }

    // Main logic of Banker's Algorithm
    // Try to find a safe sequence
    for(k=0; k<n; k++){ // Repeat for n times (Worst case)
        for(i=0; i<n; i++){ // Check each process
            if(finish[i]==0){ // If process i is not finished
                int flag=0; // Assume process can be executed

                // Check if resources needed by process i <= available resources
                for(j=0; j<m; j++){
                    if(need[i][j] > avail[j]){ 
                        flag=1; // Cannot execute this process now
                        break;
                    }
                }

                // If process can execute (need <= available)
                if(flag==0){
                    safeseq[ind++] = i; // Store process in safe sequence

                    // After execution, process releases its resources
                    for(j=0; j<m; j++){
                        avail[j] += alloc[i][j];
                    }

                    finish[i]=1; // Mark process as finished
                }
            }
        }
    }

    // Check if all processes could finish
    int safe = 1;  // Assume system is in safe state
    for(i=0; i<n; i++){
        if(finish[i]==0){ // If any process could not finish
            safe=0;
            break;
        }
    }

    if(safe){
        printf("\nSystem is in Safe State.\n");
        printf("Safe Sequence is: ");
        for(i=0; i<n; i++){
            printf("P%d ", safeseq[i]);  // Print the safe sequence
        }
    }
    else{
        printf("\nSystem is not in Safe State.\n"); // Deadlock/Unsafe state
    }

    return 0;
}
