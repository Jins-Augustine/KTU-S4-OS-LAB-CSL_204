#include<stdio.h>
void main(){
	float awt=0,att=0;
	int n,x,y,z;
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	int pid[n],btime[n],wtime[n],prio[n];
	for(int i=0;i<n;i++){
		printf("Enter the process id , burst time and priority of process %d\n",i);
		scanf("%d%d%d",&pid[i],&btime[i],&prio[i]);
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(prio[j+1]<prio[j]){
				x=prio[j];
				prio[j]=prio[j+1];
				prio[j+1]=x;
				y=pid[j];
				pid[j]=pid[j+1];
				pid[j+1]=y;
				z=btime[j];
				btime[j]=btime[j+1];
				btime[j+1]=z;
			}
		}
	}

	wtime[0]=0;
	for(int i=1;i<n;i++){
		wtime[i]=wtime[i-1]+btime[i-1];
		awt=awt+wtime[i];
	}
	int ttime[n];
	for(int i=0;i<n;i++){
		ttime[i]=wtime[i]+btime[i];
		att=att+ttime[i];
	}
	printf("\nPROCESS  ID\tPRIORITY\tBURST TIME\tWAITING TIME\tTURN AROUND TIME\t");
	for(int i=0;i<n;i++){
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\n",pid[i],prio[i],btime[i],wtime[i],ttime[i]);
	}
	printf("\nAVERAGE WAITING TIME- %f",awt);
	printf("\nAVERAGE TURN AROUND TIME-  %f",att);
	printf("\n");
	printf("\nGANT CHART\n");
	printf("\n");
	printf("\t-----------------------------------------\n");
	
	for(int i=0;i<n;i++){
		printf("\t   P[%d]",pid[i]);
	}
	int temp=0;
	printf("\n");
	printf("\t-----------------------------------------\n");
	printf("\t%d",temp);
	for(int i=0;i<n;i++){
		temp=temp+btime[i];
		printf("  \t%d",temp);
	}
	printf("\n");
}