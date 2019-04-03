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
  fgets(refstr,500,stdin);
  printf("Head? ");
  scanf("%d",&h);
  int ref[n];
  char bufstr[5];
  int j=0;
  int k=0;
  i=0;
  while(refstr[i]!='\0')
  {
    if(refstr[i]==' ')
    {
      bufstr[j]='\0';
      ref[k]=atoi(bufstr);
      k++;

      while(j>0) //to reset bufstr
      {
        j--;
        bufstr[j]='0';
      }
    }
    else
    {
      bufstr[j]=refstr[i];
      j++;
    }
    i++;
  }
  bufstr[j]='\0';
  ref[k]=atoi(bufstr);
  printf("\n%d",h);
  int x=h;
  int si=0;
  int sd=abs(ref[0]-x);
  int thm=sd;
  while(1)
  {
    int td;
    for(i=0;i<n;i++)
    {
      if(ref[i]==-1)
      continue;
      td=abs(ref[i]-x);
      if(td>0 && td<sd)
      {
        sd=td;
        si=i;
      }
    }
    printf(" --(%d)--> %d",sd,ref[si]);
    x=ref[si];
    thm+=sd;
    ref[si]=-1;
    int temp=si;
    do
    {
      si=(si+1)%n;
      if(si==temp)
      break;
    }
    while(ref[si]==-1);
    sd=abs(ref[si]-x);
    if(si==temp)
    break;
  }
  printf("\n\n");
  printf("Total Head Movement= %d\n",thm);
}
