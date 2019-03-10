#include <stdio.h>
struct Process
{
  char name;
  int at, bt, ct, wt, tat, rt, comp;
  int key;
};

void main()
{
  int n,i;
  printf("Enter the number of processes you want to insert: ");
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
    printf("Priority: ");
    scanf(" %d",&p[i].key);
    p[i].comp=0;
    p[i].ct=p[i].wt=p[i].tat=p[i].rt=0;
  }
  int t=0;
  int np=0;
  printf("Gantt chart is as follows:-\n");
  while(1)
  {
    int temp;
    temp=np;
    for(i=0;i<n;i++)
    {
      if(p[i].at<=t)
      {
        if(p[i].comp==0)
        {
          if(p[np].comp==1)
          np=i;
          else
          {
            if(p[i].key<p[np].key)
            np=i;
          }
        }
      }
    }
    if(np==temp)
    break;
    p[np].rt=t;
    p[np].wt=t-p[np].at;
    t+=p[np].bt;
    p[np].ct=t;
    p[np].tat=t-p[np].at;
    printf("%c->",p[np].name);
  }
}
