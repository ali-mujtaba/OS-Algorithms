#include <stdio.h>
struct process
{
	char name;
	int at, bt, ct, wt, tat, rt, rbt;
};
void main()
{
	int n;
	printf("\nEnter the number of processes that you want to insert: \n");
	scanf("%d",&n);
	int i;
	struct process p[n];
	for(i=0;i<n;i++) //fetching processes's info
	{
		printf("Process: ");
		scanf(" %c",&p[i].name);
		printf("Arrival Time: ");
		scanf(" %d",&p[i].at);
		printf("Burst Time: ");
		scanf(" %d",&p[i].bt);
		p[i].rbt=p[i].bt;
	}
	/*for(i=0;i<n;i++) //checking if all inputs are being stored correctly
	{
		printf("\nProcess: %c",p[i].name);
		printf("\nAT: %d",p[i].at);
		printf("\nBT: %d",p[i].rbt);
	}
	*/
	int t; //clock variable
	t=0;
	int lp; //points to the longest process
	lp=0;
	printf("\nGantt chart is as follows:-\n");
	while(1)
	{

		for(i=0;i<n;i++)
		{

			if(t>=p[i].at && p[i].rbt>0) //checks if process is in ready queue and not completed
			{
				//finds the index of the process with longest remaining time that is to be executed next.

				if(p[i].rbt>p[lp].rbt)
				lp=i;
				else if(p[i].rbt==p[lp].rbt)
				if(p[i].at<p[lp].at)
				lp=i;
			}

		}
		printf(" %c(%d) |",p[lp].name,t+1); //prints executing process
		if(p[lp].rbt==p[lp].bt) //stores first response time for each process
		p[lp].rt=t;
		p[lp].rbt--; // process execution
		t++;
		if(p[lp].rbt==0) //stores completion time for each process
		p[lp].ct=t;
		int temp;
		temp=lp;
		do //so that lp points to an unfinished process in ready queue
		{
			lp=(lp+1)%n;
			if(lp==temp)
			break;
		}while(p[lp].rbt==0);
		if(lp==temp) //case when all the processes are completely finished
		break;
	}
	float srt, swt, stat;
	srt=swt=stat=0.0;
	printf("\b \b \b \n");

	//prints process info table

	printf("\nProc \t AT \t BT \t CT \t RT \t  WT \t TAT \n");
	for(i=0;i<n;i++)
	{
		//calculate RT, TAT and WT

		p[i].rt-=p[i].at;
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		swt+=p[i].wt;
		stat+=p[i].tat;
		srt+=p[i].rt;

		//prints info for each process

		printf("%c \t %d \t %d \t %d \t %d \t %d \t %d \n",p[i].name,p[i].at,p[i].bt,p[i].ct,p[i].rt,p[i].wt,p[i].tat);
	}
	printf("\nAverage Waiting Time: %f\n",(swt/n));
	printf("Average TurnAround Time: %f\n",(stat/n));
	printf("Average Response Time: %f\n",(srt/n));

}