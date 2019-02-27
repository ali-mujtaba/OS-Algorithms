#include <stdio.h>
struct Process
{
  char name;
  int at,bt,ct,wt,tat,rt;
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
    sbt+=p[i].bt;
    p[i].comp=0;
    p[i].ct=p[i].wt=p[i].tat=p[i].rt=0;
    //printf("%d\n",sbt);
  }
  printf("Gantt chart is as follows:-\n");
  int t;
  int fc=0;
  for(t=0;t<sbt;)
  {

    /*for(i=0;i<n;i++)
    {
        if(p[i].at<=t && p[i].comp!=1
        {
            if(p[i].at<p[fc].at)
            {
              fc=i;
              printf("\nfc=%d\n",fc);
            }
        }
    }*/

    p[fc].rt=t-p[fc].at;
    p[fc].wt=t-p[fc].at;
    t+=p[fc].bt;
    p[fc].ct=t;
    p[fc].tat=p[fc].ct-p[fc].at;
    p[fc].comp=1;
    printf("%c(%d)\t",p[fc].name,t);
    fc++;
  }
  float swt=0.0,stat=0.0,srt=0.0,sct=0.0;
  printf("\nProcess \t Arrival Time \t Burst Time \t Waiting Time \t TurnAround Time \t Response Time \t Completion Time\n");
  for(i=0;i<n;i++)
  {
    printf("%c      \t           %d \t         %d \t           %d \t             %d \t              %d \t               %d\n"
              ,p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tat,p[i].rt,p[i].ct);
      swt+=p[i].wt;
      stat+=p[i].tat;
      srt+=p[i].rt;
      sct+=p[i].ct;

  }
  printf("Average TurnAround Time: %f\n",(stat/n));
  printf("Average Waiting Time: %f\n",(swt/n));
  printf("Average Response Time: %f\n",(srt/n));
  printf("Average Completion Time: %f\n",(sct/n));
}
