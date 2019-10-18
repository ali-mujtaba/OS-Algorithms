// Write a program to implement Non Pre-emptive Priority Process Scheduling Algorithm

#include <stdio.h>
struct Process
{
  char name;
  int at, bt, ct, wt, tat, rt, comp;
  int key;
};

void main()
{
  int n, i;
  printf("Enter the number of processes you want to insert: ");
  scanf("%d", &n);
  struct Process p[n];
  for (i = 0; i < n; i++) //taking processes' info from user
  {
    printf("\nProcess: ");
    scanf(" %c", &p[i].name);
    printf("Arrival Time: ");
    scanf(" %d", &p[i].at);
    printf("Burst Time: ");
    scanf(" %d", &p[i].bt);
    printf("Priority: ");
    scanf(" %d", &p[i].key);
    p[i].comp = 0;
  }
  int t = 0;
  int np = 0; //stores index of process that is to be executed next
  printf("\nGantt chart is as follows:-\n");
  while (1)
  {
    for (i = 0; i < n; i++) //finds out the priority process
    {
      if (t >= p[i].at && p[i].comp == 0)
      {
        if (p[i].key < p[np].key)
          np = i;
        else if (p[i].key == p[np].key)
        {
          if (p[i].at < p[np].at)
            np = i;
        }
      }
    }

    p[np].rt = t;
    p[np].comp = 1;
    t += p[np].bt;
    p[np].ct = t;
    p[np].tat = p[np].ct - p[np].at;
    p[np].wt = p[np].tat - p[np].bt;
    printf("| %c(%d) ", p[np].name, t);
    int c = 0;
    while (p[np].comp == 1 && c < n)
    {
      //to store index of unfinished process in ready queue
      np = (np + 1) % n;
      c++;
    }
    if (c == n) //when there is not unfinished process in ready queue
      break;
  }
  float swt = 0.0, stat = 0.0, srt = 0.0, sct = 0.0;
  printf("|\n \n");
  printf("\nProc \t Key \t AT \t BT \t CT \t WT \t TAT \t RT\n");
  for (i = 0; i < n; i++)
  {
    //display processes' info table
    printf("%c \t %d \t %d \t %d \t %d \t %d \t %d \t %d\n"
           , p[i].name, p[i].key, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat, p[i].rt);
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
