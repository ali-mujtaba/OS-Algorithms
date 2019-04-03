#include <stdio.h>
struct process
{
	char name;
	int at, bt, rbt, ct, rt, tat, wt;
	int key;
};
void main()
{
	int n;
	printf("Enter the number of processes that you want to insert: ");
	scanf("%d",&n);
	struct process p[n];
	int i;
	for(i=0;i<n;i++) 
	{
		//fetching processes' info from user
		printf("\nProcess: ");
		scanf(" %c",&p[i].name);
		printf("Arrival Time: ");
		scanf(" %d",&p[i].at);
		printf("Burst Time: ");
		scanf(" %d",&p[i].bt);
		p[i].rbt=p[i].bt;
		printf("Priority: ");
		scanf(" %d",&p[i].key);
		//printf("\n%c %d %d %d",p[i].name,p[i].at,p[i].rbt,p[i].key); //checking if values are stored correctly
		
		
	}
	int t=0; //clock variable
	int np=0; // to point to the next process that should be executed.
	printf("\nGantt chart is as follows:- \n");
	while(1)
	{
		for(i=0;i<n;i++) //finds out the process in ready queue that should be executed next
		{
			if(t>=p[i].at) //process in ready queue
			{
				if(p[i].rbt>0) //process is unfinished
				{
					if(p[i].key<p[np].key)
					np=i;
					else if(p[i].key==p[np].key)
					{
						if(p[i].at<p[np].at)
						np=i;
					}
					else;
				}
			}
		}
		
		if(p[np].rbt==p[np].bt) //storing response time
		p[np].rt=t-p[np].at;
		
		p[np].rbt--;
		t++;
		
		if(p[np].rbt==0) //storing completion time
		p[np].ct=t;
		
		printf("%c (%d)|",p[np].name,t); //displaying the executing process
		
		for(i=0;i<n+1;i++) //ensuring 'np' always point to an unfinished process in ready queue
		{
			if(p[np].rbt>0 && t>=p[np].at)
			break;
			else
			np=(np+1)%n;
		}
		if(i==n+1)
		break;
	}
	printf("\n");
	printf("\nProc \t AT \t BT \t Key \t CT \t RT \t TAT \t WT\n"); //defining process info table format
	float swt,stat,srt,sct;
	swt=stat=srt=sct=0.0;
	for(i=0;i<n;i++)
	{	
		//calculates TurnAround Time and Waiting Time for each process
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		
		//calculating sum of WT,TAT,RT,CT for computing average time
		swt+=p[i].wt;
		stat+=p[i].tat;
		srt+=p[i].rt;
		sct+=p[i].ct;
		
		//printing each process' info 
		printf("%c \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n",p[i].name,p[i].at,p[i].bt,p[i].key,p[i].ct,p[i].rt,p[i].tat,p[i].wt);
		
	}
	printf("\nAverage Waiting Time: %f\n",(swt/n));
	printf("Average Turn-Around Time: %f\n",(stat/n));
	printf("Average Response Time: %f\n",(srt/n));
	printf("Average Completion Time: %f\n",(sct/n));
}
