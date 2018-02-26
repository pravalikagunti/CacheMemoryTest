/*Program for sequential write*/

#include<stdio.h>
#include<time.h>
#include <stdlib.h>
#include <omp.h>               //open MP include file
void main()
{
	int *arr;
	arr=(int*)malloc(350000000*sizeof(int));  /*Dynamically allocating memory for an array (arr)*/
	int j;
	clock_t start_clock,end_clock;       //variables used for calculating clock
	#pragma omp parallel                 // parallel region with default number of threads
	{
		int ID=omp_get_thread_num(); //runtime library function return a thread ID
		start_clock=clock();         //start of clock
                printf("Start_Clock: %ld ofId(%d)\n",start_clock,ID); /*prints start clock time and ID*/
		for(j=0;j<350000000;j++)    // large looping
		{
			arr[j]=1;          //writing value  from an array
		}
		end_clock=clock();
		printf("End_clock: %ld of Id(%d)\n",end_clock,ID);  //prints end clock time and ID
	}   //close of pragma
	free(arr);             //free of allocated memory
}

