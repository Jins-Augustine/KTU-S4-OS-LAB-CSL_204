#include<stdio.h>
#include<stdlib.h>
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
		printf("\nPRODUCER PRODUCED ITEM %d",x);
		mutex=signal(mutex);
	}
	void consumer(){
		mutex=wait(mutex);
		full=wait(full);
		empty=signal(empty);
		printf("\nCONSUMER CONSUMED ITEM %d",x);
		mutex=signal(mutex);
		x--;
	}
int main(){
	int n,ch;
	
	while(1){
		printf("\nChoose the operation you want to perform\n");
		printf("\n1:PRODUCE\n2:CONSUME\n3:EXIT\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: if(mutex==1 && empty!=0){
				producer();
				}
				else{
					printf("\nTHE BUFFER IS FULL");
				}
				break;
			case 2: if(mutex==1 && full!=0){
				consumer();
				}
				else{
					printf("\nTHE BUFFER IS EMPTY");
				}
				break;
			case 3: printf("\nExiting....");
				exit(0);
				break;
			default:printf("\nInvalid choice\n");
		}
	}
}
