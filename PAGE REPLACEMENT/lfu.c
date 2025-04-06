#include<stdio.h>
void main(){
    int i,k,n,pages[20],framecount,frames[10],frequency[20];
    int avail,page_fault=0;
    printf("\n\tLFU PAGE REPLACEMENT SCHEME\n");
    printf("Enter the number of pages: ");
    scanf("%d",&n);
    printf("Enter the page numbers: ");
    for(i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d",&framecount);
    for(i=0;i<framecount;i++){
        frames[i]=-1;
        frequency[i]=0;
    }

    printf("\nRef_String\tPage_Frames\n");

    for(i=0;i<n;i++){
        printf("%d\t\t",pages[i]);
        avail=0;

        for(k=0;k<framecount;k++){
            if(frames[k]==pages[i]){
                avail=1;
                frequency[k]++;
                break;
            }
        }
        if(avail==0){
            int min_index=0;
            int min_freq=frequency[0];

            for(k=1;k<framecount;k++){
                if(frequency[k]<min_freq){
                    min_freq=frequency[k];
                    min_index=k;
                }
            }
            frames[min_index]=pages[i];
            frequency[min_index]=1;
            page_fault++;

            for(k=0;k<framecount;k++){
                if(frames[k]!=-1){
                    printf("%d\t",frames[k]);
                }
                else
                    printf("-\t");
            }
        }
        else{
            printf("hit");
        }
        printf("\n");
    }

    printf("\nNumber of page faults: %d",page_fault);
}