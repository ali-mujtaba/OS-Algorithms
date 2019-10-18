//Write a program to implement Least-Recently-Used Page Replacement Algorithm

#include <stdio.h>
#include <stdlib.h>
#define n 12

int leastRecent(int arr[], int f, int subref[], int nr)
{
  int i, j;
  int lastUse[f];
  for (i = 0; i < f; i++)
    lastUse[i] = 0;
  // printf("Subref string: ");
  // for(i=0;i<nr;i++)
  // printf("%d ", subref[i]);
  // printf("\n");
  for (i = 0; i < f; i++)
  {
    for (j = 0; j < nr; j++)
      if (subref[j] == arr[i])
        lastUse[i] = j;
  }
  // for(i=0;i<f;i++)
  // printf("Freq of %d: %d\n",arr[i],freq[i]);
  int lru = 0;
  for (i = 0; i < f; i++)
    if (lastUse[i] < lastUse[lru])
      lru = i;
  // for(i=0;i<f-1;i++)
  // if(freq[i]!=freq[i+1])
  // break;
  //
  // if(i==f-1)
  // return -1;
  //printf("Least Frequent: %d\n",subref[lf]);
  return lru;
}
// int relative(int arr[], int f, int subref[], int nr)
// {
//   int i,j;
//   int rd[f];
//   for(j=0;j<f;j++)
//   {
//     for(i=nr-1;i>=0;i--)
//     {
//       if(subref[i]==arr[j])
//       {
//         rd[j]=i;
//         break;
//       }
//     }
//   }
//   int t=0;
//   // for(i=0;i<nr;i++)
//   // {
//   //   for(j=0;j<f;j++)
//   //   if(subref[i]==arr[j])
//   //     break;
//   //   if(j<nr)
//   //   break;
//   // }
//   int lr=0;
//   for(i=0;i<f;i++)
//   if(rd[i]<rd[lr])
//   lr=i;
//   return lr;
// }
int pagecheck(int arr[], int f, int p)
{
  int i;
  for (i = 0; i < f; i++)
  {
    if (arr[i] == p)
      return 1;
  }
  return -1;
}

void main()
{
  int i;
  int hit = 0, fault = 0;
  printf("Reference String? ");
  char refstr[500];
  fgets(refstr, 500, stdin);
  int ref[n];
  char bufstr[5];
  int thm = 0;
  int j = 0;
  int k = 0;
  i = 0;
  while (refstr[i] != '\0')
  {
    if (refstr[i] == ' ')
    {
      bufstr[j] = '\0';
      ref[k] = atoi(bufstr);
      k++;

      while (j > 0) //to reset bufstr
      {
        j--;
        bufstr[j] = '\0';
      }
    }
    else
    {
      bufstr[j] = refstr[i];
      j++;
    }
    i++;
  }
  bufstr[j] = '\0';
  ref[k] = atoi(bufstr);
  int nof;
  printf("Enter the number of frames: ");
  scanf("%d", &nof);
  int frames[n];
  for (i = 0; i < nof; i++)
    frames[i] = -99;
  // int rf=0; //pointing to the frame to be replaced.
  for (i = 0; i < n; i++)
  {
    if (pagecheck(frames, nof, ref[i]) == -1)
    {
      printf("Page Fault: %d\n", ref[i]);
      fault++;
      if (i < nof)
        frames[i] = ref[i];
      else
      {
        int subref[i];

        for (j = 0; j < i; j++)
          subref[j] = ref[j];

        int rf = leastRecent(frames, nof, subref, i);
        // if(rf==-1)
        // rf=relative(frames,nof,subref,i);

        frames[rf] = ref[i];
      }
      // rf=(rf+1)%nof;
    }
    else
    {
      printf("Hit: %d\n", ref[i]);
      hit++;
    }

    //displaying status of frame after every hit or fault
    for (j = 0; j < nof; j++)
      if (frames[j] == -99)
        printf("- ");
      else
        printf("%d ", frames[j]);
    printf("\n");
  }

  printf("\nNo. of hits: %d\n", hit);
  printf("No. of page faults: %d\n", fault);
}
