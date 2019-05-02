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
  int thm=0;
  int d=abs(ref[0]-h);
  printf("\n%d --(%d)--> %d",h,d,ref[0]);
  thm+=d;
  for(i=1;i<n;i++)
  {
    d=abs(ref[i]-ref[i-1]);
    printf(" --(%d)--> %d",d,ref[i]);
    thm+=d;
  }
  printf("\n\nTotal Head Movement: %d\n",thm);
}
