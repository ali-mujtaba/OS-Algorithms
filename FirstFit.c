//Write a program to implement First Fit Memory Management Algorithm
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
  j = 0;
  for (j = 0; j < n; j++)
  {
    for (i = 0; i < m; i++)
      if (p[j] <= mem[i].asize && mem[i].p == -99)
      {
        mem[i].p = j;
        mem[i].asize -= p[j];
        break;
      }
    // if(i>=m)
    // ef+=p[j];
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
