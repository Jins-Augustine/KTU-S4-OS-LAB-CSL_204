#include<stdio.h>
void main(){
    int n,head,distance,seek_time=0;
    printf("Enter the head position: ");
    scanf("%d",&head);
    printf("Enter the number of requests: ");
    scanf("%d",&n);
    int requests[n];

    printf("Enter the requests: ");
    for(int i=0;i<n;i++){
        scanf("%d",&requests[i]);
    }

    printf("\n\tFCFS DISK SCHEDULING\n\n");
    int current =head;
    for(int i=0;i<n;i++){
        distance=(requests[i]>current)?(requests[i]-current):(current-requests[i]);
        printf("Head moves from %d to %d: %d",current,requests[i],distance);
        seek_time+=distance;
        current=requests[i];
    }
    printf("\nTotal seek time: %d",seek_time);
    
}