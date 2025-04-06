#include<stdio.h>
void main(){
    int i,j,k,n,pages[50],framecount,frames[10],time[10];
    int avail,page_fault=0;
    int lru_index,least_time;
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
        time[i]=0;
    }

    printf("\nRef_String\tPage_Frames\n");
    for(i=0;i<n;i++){
        printf("%d\t\t",pages[i]);
        avail=0;

        for(k=0;k<framecount;k++){
            if(frames[k]==pages[i]){
                avail=1;
                time[k]=i;
                break;
            }
        }

        if(avail==0){
            if(i<framecount){
                frames[i]=pages[i];
                time[i]=i;
            }
            else{
                lru_index=0;
                least_time=time[0];
                for(k=1;k<framecount;k++){
                    if(time[k]<least_time){
                        least_time=time[k];
                        lru_index=k;
                    }
                }
                frames[lru_index]=pages[i];
                time[lru_index]=i;

            }
            page_fault++;

            for(k=0;k<framecount;k++){
                if(frames[k]!=-1){
                    printf("%d\t",frames[k]);
                }
                else{
                    printf("-\t");
                }
            }
        }
        else{
            printf("hit");
        }

        printf("\n");
        

       
    }
    printf("Page Faults: %d",page_fault);
}