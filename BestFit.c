//Write a program to implement Best Fit Memory Management Algorithm
#include <stdio.h>
struct memory
{
  int size;
  int asize;
  int p;
};
void main()
{
  int m, n, i, j;
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  int p[n];
  printf("Enter the number of memory blocks you have: ");
  scanf("%d", &m);
  struct memory mem[m];
  printf("Enter size of memory blocks:-\n");
  for (i = 0; i < m; i++)
  {
    printf("Block[%d]: ", i + 1);
    scanf("%d", &mem[i].size);
    mem[i].asize = mem[i].size;
    mem[i].p = -99;
  }
  int ef = 0;
  printf("Enter the processes below:-\n");
  for (i = 0; i < n; i++)
  {
    printf("Process[%d]: ", i + 1);
    scanf("%d", &p[i]);
  }

  int bb; //to point to the best block for a process
  for (i = 0; i < n; i++)
  {
    int sd = -1; //to compare available size differences in order to find best block

    for (j = 0; j < m; j++)
      if (mem[j].p == -99 && (mem[j].asize - p[i]) > 0)
        break;
    if (j == m)
      continue;
    bb = j; //initially best block is assumed to be any block that can accomodate that process
    sd = mem[bb].asize - p[i];
    for (j = bb + 1; j < m; j++)
    {
      if (mem[j].p == -99 && mem[j].asize - p[i] >= 0 && mem[j].asize - p[i] < sd)
      {
        sd = mem[j].asize - p[i];
        bb = j;
      }
    }
    mem[bb].p = i;
    mem[bb].asize -= p[i];
  }
  int tam = 0;
  int tif = 0;
  printf("\nMemory Allocation is as follows:-\n");
  for (i = 0; i < m; i++)
    if (mem[i].p != -99)
    {
      printf("\t%d(P%d) IF=(%d)\t|", mem[i].size, mem[i].p + 1, mem[i].asize);
      tif += mem[i].asize;
    }
    else
    {
      printf("\t%d\t|", mem[i].size);
      tam += mem[i].size;
    }



  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      if (i == mem[j].p)
        break;
    }
    if (j >= m && tam >= p[i])
      ef += p[i];
  }
  printf("\n\nTotal Internal Fragmentation= %d\n", tif);
  printf("Total External Fragmentation= %d\n", ef);

}
