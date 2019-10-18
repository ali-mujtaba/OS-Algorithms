//Write a program to implement First-In-First-Out Page Replacement Algorithm

#include <stdio.h>
#include <stdlib.h>
#define n 20

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
  int rf = 0; //pointing to the frame to be replaced.
  for (i = 0; i < n; i++)
  {
    if (pagecheck(frames, nof, ref[i]) == -1)
    {
      printf("Page Fault: %d\n", ref[i]);
      fault++;
      frames[rf] = ref[i];
      rf = (rf + 1) % nof;
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
