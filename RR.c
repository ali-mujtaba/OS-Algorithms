//Write a program to implement Round Robin Process Scheduling Algorithm
#include <stdio.h>
#define tq 3
struct Process
{
  char name;
  int at, bt, ct, wt, tat, rt, rbt;
  int comp;
};
void main()
{
  int n, i;
  printf("Enter the number of processes you want to insert: \n");
  scanf("%d", &n);
  struct Process p[n];
  for (i = 0; i < n; i++)
  {
    printf("\nProcess: ");
    scanf(" %c", &p[i].name);
    printf("Arrival Time: ");
    scanf(" %d", &p[i].at);
    printf("Burst Time: ");
    scanf(" %d", &p[i].bt);
    p[i].rbt = p[i].bt;
    p[i].comp = 0;
    p[i].ct = p[i].wt = p[i].tat = p[i].rt = 0;
  }
  int a;
  struct Process temp;
  int j;
  for (i = 0; i < n - 1; i++) //sorts the process in order of their arrival.
  {
    a = i;
    for (j = i + 1; j < n; j++)
    {
      if (p[j].at < p[a].at)
        a = j;
    }
    temp = p[i];
    p[i] = p[a];
    p[a] = temp;
  }
  printf("\n");

  int t = 0;
  int np = 0;
  while (1)
  {
    if (t >= p[np].at)
    {
      //process arrived
      if (p[np].rbt > 0)
      {
        if (p[np].rbt == p[np].bt)
          p[np].rt = t;
        //process in ready queue
        if (p[np].rbt >= tq)
        {
          t += tq;
          p[np].rbt -= tq;
          p[np].ct = t;
          printf(" %c(%d) |", p[np].name, t);
        }
        else
        {
          t += p[np].rbt;
          p[np].rbt = 0;
          p[np].ct = t;
          printf(" %c(%d) |", p[np].name, t);
        }
      }
      else;
      //process arrived and finished executing
    }
    else;
    //process hasn't even arrived in ready queue yet

    np = (np + 1) % n;
    int flag = 0;
    for (i = 0; i < n; i++) //checks if there is any unfinished process
      if (p[i].rbt > 0)
        flag = 1;

    if (flag == 0) //when there are no unfinished processes
      break;
  }
  printf("\n");
  float swt = 0.0, stat = 0.0, srt = 0.0, sct = 0.0;
  printf("\nProc \t AT \t BT \t CT \t RT \t TAT \t WT\n");
  //format for Process info table
  for (i = 0; i < n; i++) //
  {
    //calculates TAT and WT for each process
    p[i].tat = p[i].ct - p[i].at;
    p[i].wt = p[i].tat - p[i].bt;
    //prints process info table
    printf("%c \t %d \t %d \t %d \t %d \t %d \t %d\n"
           , p[i].name, p[i].at, p[i].bt, p[i].ct, p[i].rt, p[i].tat, p[i].wt);
    swt += p[i].wt;
    stat += p[i].tat;
    srt += p[i].rt;
    sct += p[i].ct;
  }

  printf("Average TurnAround Time: %f\n", (stat / n));
  printf("Average Waiting Time: %f\n", (swt / n));
  printf("Average Response Time: %f\n", (srt / n));
  printf("Average Completion Time: %f\n", (sct / n));
  printf("\n");
}
