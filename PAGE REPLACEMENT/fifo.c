//FIFO
#include<stdio.h>
void main(){
    int n,pages[20],numframe,frame[10],i,j=0,k,available,pagefault=0;

    printf("Enter the number of pages: ");
    scanf("%d",&n);
    printf("Enter the page numbers: ");
    for(i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d",&numframe);

    for(i=0;i<numframe;i++){
        frame[i]=-1;
    }
    printf("\nRef_String\tPage_Frames\n");
    
    for(i=0;i<n;i++){
        printf("%d\t\t",pages[i]);
        available=0;

        for(k=0;k<numframe;k++){
            if(frame[k]==pages[i]){
                available=1;
                break;
            }
        }

        if(available==0){
            frame[j]=pages[i];
            j=(j+1)%numframe;
            pagefault++;

            for(k=0;k<numframe;k++){
                if(frame[k]!=-1){
                    printf("%d\t",frame[k]);
                }
                else
                    printf("-\t");
            }
        }
        printf("\n");
    }
    printf("\nTotal Page Faults: %d\n",pagefault);
}
    
