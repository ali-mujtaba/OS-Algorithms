#include <stdio.h>
#define tq 2
struct Process
{
  char name;
  int at,bt,ct,wt,tat,rt,rbt;
  int comp;
};
void main()
{
  int n,i,sbt=0;
  printf("Enter the number of processes you want to insert: \n");
  scanf("%d",&n);
  struct Process p[n];
  for(i=0;i<n;i++)
  {
    printf("\nProcess: ");
    scanf(" %c",&p[i].name);
    printf("Arrival Time: ");
    scanf(" %d",&p[i].at);
    printf("Burst Time: ");
    scanf(" %d",&p[i].bt);
    p[i].rbt=p[i].bt;
    sbt+=p[i].bt;
    p[i].comp=0;
    p[i].ct=p[i].wt=p[i].tat=p[i].rt=0;
  }
  int j=0;
  int flag=0;
  int t=0;
  while(flag==0)
  {
      if(p[j].at<=t && p[j].comp!=1)
      {
        printf("HI\n");
        if(p[j].rbt<=tq)
        {
          if(p[j].rbt==p[j].bt)
          p[j].rt=t;
          t+=p[j].rbt;
          p[j].comp=1;
          p[j].ct=t;
          p[j].wt=p[j].ct-p[j].at-p[j].bt;
          p[j].tat=p[j].ct-p[j].at;
        }
        else
        {
          if(p[j].rbt==p[j].bt)
          p[j].rt=t;
          printf("%c(%d)->",p[j].name,t);
          t+=tq;
          p[j].rbt-=tq;
        }
      }
        j++;
        if(j>=n)
        j=0;
        for(i=0;i<n;i++)
        {
          if(p[i].comp==1)
          flag=1;
          else
          flag=0;
        }
        printf("\nFlag=%d\n",flag);
  }
  printf("\nProcess \t Arrival Time \t Burst Time \t Waiting Time \t TurnAround Time \t Response Time \t Completion Time\n");
  for(i=0;i<n;i++)
  {
    printf("%c      \t           %d \t         %d \t           %d \t             %d \t              %d \t               %d\n"
              ,p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tat,p[i].rt,p[i].ct);
  }
}
