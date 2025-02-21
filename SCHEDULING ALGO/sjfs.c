#include<stdio.h>
void main(){
    int n;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    int wt[n],bt[n],tat[n],p[n];
    float awt=0,att=0;
    for(int i=0;i<n;i++){
        printf("Enter the process id:");
        scanf("%d",&p[i]);
        printf("Enter the burst time of process %d:",p[i]);
        scanf("%d",&bt[p[i]]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(bt[p[j]] > bt[p[j+1]]){
                int temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[p[i-1]];
        awt+=wt[i];
    }
    for(int i=0;i<n;i++){
        tat[i]=wt[i]+bt[p[i]];
        att+=tat[i];
    }
    printf("\nPROCESS\t\tBURST TIME\t\tWAITING TIME\t\tTURNAROUND TIME\n");
        printf("___________________________________________________________________________________\n");
        for(int i=0;i<n;i++){
            printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n",p[i],bt[p[i]],wt[i],tat[i]);
        }
        printf("Average waiting time : %f\n",awt/n);
        printf("Average turn around time : %f\n",att/n);
        printf("\n");
        printf("GANTT CHART\n");
        printf("\n");
        printf("\t-------------------------------------\n");
        for(int i=0;i<n;i++){
            printf("\t   P[%d]",p[i]);
        }
        printf("\n\t-------------------------------------\n");
        int temp=0;
        printf("\t0");
        for(int i=0;i<n;i++){
            temp+=bt[p[i]];
            printf("\t %d",temp);
        }

}
    

