#include<stdio.h>
#include<stdlib.h>
int main(){
    int empty=3,full=0,mutex=1,x=0;
    int wait(int s){
        return(--s);
    }
    int signal(int s){
        return(++s);
    }
    void producer(){
        mutex=wait(mutex);
        empty=wait(empty);
        full=signal(full);
        x++;
        printf("Produced: %d\n",x);
        mutex=signal(mutex);
    }
    void consumer(){
        mutex=wait(mutex);
        full=wait(full);
        empty=signal(empty);
        printf("Consumed: %d\n",x);
        x--;
        mutex=signal(mutex);
    }
    while(1){
        printf("\nChoose option\n1:Producer\n2:Consumer\n3:Exit\n");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:if(mutex==1 && empty!=0){
                producer();
                }
                else{
                    printf("Buffer is full\n");
                }
                break;
                
            case 2: if(mutex==1 && full!=0){
                consumer();
                }
                else{
                    printf("Buffer is empty\n");
                }
                break;
            case 3: exit(0);
                break;
            default:printf("Invalid choice\n");
                break;
                    

        }
    }
    return 0;
}