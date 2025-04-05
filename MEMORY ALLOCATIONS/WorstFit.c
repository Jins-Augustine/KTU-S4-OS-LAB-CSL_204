#include<stdio.h>
int main(){
    int np,nb;
    printf("Enter the number of processes: ");
    scanf("%d",&np);
    printf("Enter the number of blocks: ");
    scanf("%d",&nb);
    struct process{
        int ps;
        int flag;
    }p[np];
    struct block{
        int bs;
        int alloc;
    }b[nb];
    for(int  i=0;i<np;i++){
        printf("Enter the size of process %d: ",i+1);
        scanf("%d",&p[i].ps);
        p[i].flag=0;
    }
    for(int i=0;i<nb;i++){
        printf("Enter the size of block %d:",i+1);
        scanf("%d",&b[i].bs);
        b[i].alloc=0;
    }
    for(int i=0;i<nb-1;i++){
        for(int j=0;j<nb-i-1;j++){
            if(b[j].bs<b[j+1].bs){
                struct block x=b[j];
                b[j]=b[j+1];
                b[j+1]=x;
            }
        }
    }
    printf("\nPROCESS\t\tSIZE\t\tBLOCK");
    printf("\n____\t\t____\t\t____\n");
    for(int i=0;i<np;i++){
        for(int j=0;j<nb;j++){
            if(p[i].flag==0 && b[j].alloc==0 && p[i].ps<=b[j].bs){
                p[i].flag=1;
                b[j].alloc=1;
                printf("\n%d\t\t%d\t\t%d",i+1,p[i].ps,b[j].bs);
            }
        }
    }
    printf("\n");
    for(int i=0;i<np;i++){
        if(p[i].flag==0){
            printf("\nProcess %d cannot be allocated",i+1);
        }
    }
    return 0;
    
}