//Write a program to implement Highest-Response-Ratio-Next Process Scheduling Algorithm
#include <stdio.h>
struct process
{
	char name;
	int at, bt, ct, wt, tat, rt, rr;
	int comp;
};
void main()
{
	int n;
	printf("\nEnter the number of processes that you want to insert: \n");
	scanf("%d", &n);
	int i, j;
	struct process p[n];

	for (i = 0; i < n; i++) //fetching processes's info from user
	{
		printf("Process: ");
		scanf(" %c", &p[i].name);
		printf("Arrival Time: ");
		scanf(" %d", &p[i].at);
		printf("Burst Time: ");
		scanf(" %d", &p[i].bt);
		p[i].comp = -1;
		p[i].rr = 0;
		p[i].wt = 0;
	}
	/*for(i=0;i<n;i++) //checking if all inputs are being stored correctly
	{
		printf("\nProcess: %c",p[i].name);
		printf("\nAT: %d",p[i].at);
		printf("\nBT: %d",p[i].rbt);
	}
	*/
	int t; //clock variable
	t = 0;
	int np; //points to the next process to be executed
	np = 0;
	printf("\nGantt chart is as follows:-\n");
	printf(" (0)|");

	for (i = 0; i < n; i++) //to get index of the process with earliest AT
		if (p[i].at < p[np].at)
			np = i;

	for (i = 0; i < n; i++)
	{
		//starting execution of processes with the one that arrived first
		p[np].rt = t;
		t += p[np].bt;
		p[np].ct = t;
		printf("%c (%d)|", p[np].name, t);
		p[np].comp = 1; //process finished
		for (j = 0; j < n; j++)
		{
			if (p[j].comp == -1 && t >= p[j].at)
			{
				//update waiting time and response ratio of processes in ready queue
				p[j].wt = t - p[j].at;
				p[j].rr = (p[j].wt + p[j].bt) / p[j].bt;

				//point 'np' to that unfinished process with highest response ratio
				if (p[np].comp == 1)
					np = j;
				else
				{
					if (p[j].rr > p[np].rr)
						np = j;
				}
			}
		}
	}
	float sct, srt, swt, stat;
	sct = srt = swt = stat = 0.0;
	printf("\n");

	//prints process info table

	printf("\nProc \t AT \t BT \t CT \t RT \t  WT \t TAT \n");
	for (i = 0; i < n; i++)
	{
		//calculate RT, TAT and WT

		p[i].rt -= p[i].at;
		p[i].tat = p[i].ct - p[i].at;
		swt += p[i].wt;
		stat += p[i].tat;
		srt += p[i].rt;
		sct += p[i].ct;

		//prints info for each process

		printf("%c \t %d \t %d \t %d \t %d \t %d \t %d \n", p[i].name, p[i].at, p[i].bt, p[i].ct, p[i].rt, p[i].wt, p[i].tat);
	}

	printf("\nAverage Waiting Time: %f\n", (swt / n));
	printf("Average TurnAround Time: %f\n", (stat / n));
	printf("Average Response Time: %f\n", (srt / n));
	printf("Average Completion Time: %f\n", (sct / n));

}
