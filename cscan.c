//Write a program to implement C-Scan Disk Scheduling Algorithm
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
  int ci = ref[si] - h >= 0 ? si + 1 : si - 1;
  do
  {
    if (ref[si] - h >= 0)
    {
      printf(" --(%d)--> %d", abs(ref[ci] - ref[ci - 1]), ref[ci]);
      thm += abs(ref[ci] - ref[ci - 1]);
      ci = (ci + 1) % n;
      if (ci == si)
        break;
      if (ci == 0)
      {
        printf(" --(%d)--> 199", abs(199 - ref[n - 1]));
        thm += 199 - ref[n - 1];
        printf(" --(199)--> 0");
        thm += 199;
        printf(" --(%d)--> (%d)", ref[0], ref[0]);
        thm += ref[0];
        ci++;
      }
    }
    else
    {
      printf(" --(%d)--> %d", abs(ref[ci] - ref[ci + 1]), ref[ci]);
      thm += abs(ref[ci] - ref[ci + 1]);
      ci = (ci - 1) % n;
      if (ci == si)
        break;
      if (ci < 0)
      {
        printf(" --(%d)--> 0", abs(ref[0]));
        thm += ref[0];
        printf(" --(199)--> 199");
        thm += 199;
        printf(" --(%d)--> (%d)", 199 - ref[n - 1], ref[n - 1]);
        thm += 199 - ref[n - 1];
        ci = n - 1;
      }
    }
  } while (1);
  printf("\nTotal Head Movement= %d\n", thm);
}
