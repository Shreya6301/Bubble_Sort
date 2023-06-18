#include <stdio.h>
#include <stdlib.h>
#include<time.h>



void bubble_sort(long int *a, long n)
{
  long int i, j, t;

  for (i = 0 ; i < ( n - 1 ); i++)
  {
    for (j = 0 ; j < n - i - 1; j++)
    {
      if (a[j] > a[j+1])
      {
        /* Swapping */

        t = a[j];
        a[j] = a[j+1];
        a[j+1]= t;
      }
    }
  }
}

int main()
{
    FILE *fp;
    clock_t t1,t2,time_taken;
    long int *ptr;
    long int i,m;


   fp=fopen("sort.txt","w");

   for(m=10000;m<100000;m=m+10000)
   {
       ptr=(long int*)malloc(m * sizeof(long int));
        for(i=0;i<m;i++)
        {
            ptr[i]=rand();
            //printf("%ld\n",ptr[i]);
        }
        t1=clock();
        bubble_sort(ptr,m);
        t2=clock();
        //for(i=0;i<m;i++)
        //printf("%ld\n",ptr[i]);
        time_taken=t2-t1/CLOCKS_PER_SEC;
        fprintf(fp,"%ld\t%ld\n",m,time_taken);

   }
   fclose(fp);
   return 0;
}




