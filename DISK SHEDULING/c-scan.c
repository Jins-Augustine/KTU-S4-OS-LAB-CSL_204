#include<stdio.h>
void main(){
    int head,n,a[50],size,seek_time=0,pos;
    printf("Enter the head position: ");
    scanf("%d",&head);
    printf("Enter the number of requests: ");
    scanf("%d",&n);
    printf("Enter the disk size: ");
    scanf("%d",&size);

    printf("Enter the requests: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    a[n]=head;
    n++;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(a[i]==head){
            pos=i;
            break;
        }
    }

    printf("\n\tC-SCAN DISK SCHEDULING\n\n");
    for(int i=pos;i<n-1;i++){
        seek_time+=a[i+1]-a[i];
        printf("\nHead moves from %d to %d: %d",a[i],a[i+1],a[i+1]-a[i]);
    }
    //moves to end of disk
    if(a[n-1]!=size-1){
        seek_time+=size-1 - a[n-1];
        printf("\nHead moves from %d to %d: %d",a[n-1],size-1,size-1 - a[n-1]);
    }
    //move to start going left
    printf("Jump from %d to 0: %d",size-1,size-1);
    seek_time+=size-1;

    for(int i=0;i<pos;i++){
        seek_time+=a[i+1]-a[i];
        printf("\nHead moves from %d to %d: %d",a[i],a[i+1],a[i+1]-a[i]);
    }
}