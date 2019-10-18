//Write a program to implement Look Disk Scheduling Algorithm
#include <stdio.h>
#include <stdlib.h>
#define n 8
void main()
{
  int h;
  int i;

  //scanf("\n");
  //fgets(refstr,1,stdin);
  printf("Reference String? ");
  char refstr[500];
  fgets(refstr, 500, stdin);
  printf("Head? ");
  scanf("%d", &h);
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
        bufstr[j] = '0';
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
  //printf("\n%d\n",h);
  int p, temp;
  for (i = 0; i < n - 1; i++) //sorting reference string
  {
    p = i;
    for (j = i + 1; j < n; j++)
    {
      if (ref[j] < ref[p])
        p = j;
    }
    temp = ref[i];
    ref[i] = ref[p];
    ref[p] = temp;
  }
  // for(i=0;i<n;i++) checking the ref string array
  // {
  //   printf("%d\n",ref[i]);
  // }
  int si; //store starting index

  //finding the index to start with
  if (h < ref[0])
    si = 0;
  if (h > ref[n - 1])
    si = 0;
  if (h > ref[0] && h < ref[n - 1])
  {
    for (i = 1; i < n; i++)
    {
      if (h < ref[i])
      {
        if (abs(ref[i] - h) >= abs(ref[i - 1] - h))
          si = i;
        else
          si = i - 1;
        break;
      }

    }
  }

  //printf("\nstart with: %d\n",ref[si]);
  printf("\n%d --(%d)--> %d", h, abs(ref[si] - h), ref[si]);
  thm += abs(ref[si] - h);
  int count = 0;
  int ci = ref[si] - h >= 0 ? si + 1 : si - 1;
  do
  {

    if (ref[si] - h >= 0)
    {
      printf(" --(%d)--> %d", abs(ref[ci] - ref[ci - 1]), ref[ci]);
      count++;
      thm += abs(ref[ci] - ref[ci - 1]);
      if (count >= n - 1)
        break;
      ci++;
      if (ci == n)
      {
        if (si <= 0)
          break;
        else
        {
          si--;
          printf(" --(%d)--> %d", abs(ref[si] - ref[n - 1]), ref[si]);
          count++;
          if (count >= n - 1)
            break;
          thm += abs(ref[si] - ref[n - 1]);
          ci = si - 1;

        }

      }

    }
    else
    {
      printf(" --(%d)--> %d", abs(ref[ci] - ref[ci + 1]), ref[ci]);
      count++;
      thm += abs(ref[ci] - ref[ci + 1]);
      if (count >= n - 1)
        break;
      ci--;

      if (ci < 0)
      {

        if (si >= n - 1)
          break;
        else
        {
          si++;
          printf(" --(%d)--> %d", abs(ref[si] - ref[0]), ref[si]);
          count++;
          thm += abs(ref[si] - ref[0]);
          if (count >= n - 1)
            break;
          ci = si + 1;
        }
      }
    }
  } while (1);
  printf("\nTotal Head Movement= %d\n", thm);
}
