/**********************************************************************/
/*																	  */
/* Program Name:   program3 - Sum of Experimental Scientific Data     */
/* Author:		   Ethan Pinto										  */
/* Installation:   Pensacola Christian College, Pensacola, Florida    */
/* Course:		   CS227, Data Structures and Algorithms			  */
/* Date Written:   October 14, 2016						    		  */
/*																	  */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* I pledge  all of the lines  in this C program  are my own original */
/* work and that none of the lines in this C program have been copied */
/* from anyone else, unless I was specifically authorized to do so by */
/*                        my CS227 instructor.                        */
/*                                                                    */
/*                                                                    */
/*                      Signed: _____________________________________ */
/*                                           (signature)              */
/*                                                                    */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* This program assigns a list of experimental scientific data to an  */
/* array, sorts the arrary into descending order, and then calculates */
/* the sum of the data.                                               */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**********************************************************************/
/*                        Symbolic Constants                          */
/**********************************************************************/
#define PROGRAM_NUMBER 3       /* Teacher assigned course number      */
#define LAST_NAME      "Pinto" /* The programmers last name           */  
#define COURSE_NUMBER  "CS227" /* PCC Assigned Course Number          */
#define MIN_QUANTITY   2       /* Minimum quantity of data            */ 
#define MAX_QUANTITY   100     /* Maximum quantity of data            */
#define QUIT           0       /* Program exit value                  */
#define DATA_ALLOC_ERR 1       /* Can't allocate memory for scientific*/
                               /* data                                */
#define SORT_ALLOC_ERR 2       /* Can't allocate memory for sort      */
                               /* function                            */

/**********************************************************************/
/*                       Function Prototypes                          */
/**********************************************************************/
void print_heading();
   /* Prints the program heading                                      */
void print_instructions();
   /* Prints the program instructions                                 */
int get_data_quantity();
   /* Gets the number of data values                                  */
void get_scientific_data(int quantity, float *p_data);
   /* Gets the scientific data values                                 */
void sort_data(int quantity, float *p_data);
   /* Sorts the experimental scientific data into descending order    */
void print_data(int quantity, float *p_data);
   /* Prints the scientific data values                               */
float calculate_sum(int quantity, float *p_data);
   /* Calculates the sum of all the scientific data values            */
void print_sum(float data_sum);   
   /* Prints the sum of all the scientific data values                */
   
/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   float *p_data;  /* Array of experimental scientific data values    */
   int   quantity; /* Number of experimental scientific data values   */
	
   /* Prints the program heading                                      */
   printf("\n\n\n\n\n\n\n");
   print_heading();
	
   /* Loop processing experimental scientific data until user quits   */
   while(print_instructions(), (quantity = get_data_quantity()) != 
																   QUIT)
   {
   	
      /* Allocates memory for experimental scientific data values and */
      /* aborts if an error occurs                                    */
	  if ((p_data = (float *) malloc(sizeof(p_data) * quantity)) == 
																   NULL)
	  {
         printf("\nError # %s occured in main().", DATA_ALLOC_ERR);
		 printf("\nCan't allocate memory for scientific data");
		 printf("\nThe program is aborting");
		 exit(DATA_ALLOC_ERR);
      }
     	
         /* Gets the experimental scientific data                     */
     	 get_scientific_data(quantity, p_data);
     	 /* Sorts the experimental scientific data                    */
     	 sort_data(quantity, p_data);
     	 /* Prints the experimental scientific data                   */
     	 print_data(quantity, p_data);
     	 /* Prints the sum of the experimental scientific data        */
     	 print_sum(calculate_sum(quantity, p_data));
     	
         /* Frees allocated memory for experimental scientific data   */
     	 free(p_data);
   }
   
   /* Prints a goodbye message and terminates the program             */
   printf("\n\nThanks for using this program.  Have a nice day! ;-)");
   printf("\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                     Prints the Program Heading                     */
/**********************************************************************/
void print_heading()
{
   printf("\n======================================================");
   printf("\n               Program Number: %d",    PROGRAM_NUMBER);
   printf("\n               Programmer: %s",        LAST_NAME);
   printf("\n               PCC Course Number: %s", COURSE_NUMBER);
   printf("\n======================================================");
   return;
}

/**********************************************************************/
/*                       Prints the Instructions                      */
/**********************************************************************/
void print_instructions()
{
   printf("\n\n\n");
   printf(  "This program processes experimental scientific data");
   printf("\n-----------------------------------------------------");
   return;
}

/**********************************************************************/
/*                   Gets the Number of Data Values                   */
/**********************************************************************/
int get_data_quantity()
{
   int quantity; /* Number of experimental scientific data values     */
	
   do
   {
      printf("\nHow many data values are there (%d to ", MIN_QUANTITY);
	  printf("%d, %d = quit): ", MAX_QUANTITY, QUIT);
	  scanf ("%d", &quantity);
   }
   while(quantity != QUIT && (quantity < MIN_QUANTITY || quantity >
   														 MAX_QUANTITY));
   return quantity;
}

/**********************************************************************/
/*               Gets the Experimental Scientific Data                */
/**********************************************************************/
void get_scientific_data(int quantity, float *p_data)
{
   int counter; /* */
   /* put this into the for loop*/
   for(counter = 0.0f; counter < quantity; counter++)
   {
      printf("    Enter data value %d: ", counter + 1);
	  scanf ("%f", p_data);
	  *p_data++;
   }
   return;
}

/**********************************************************************/
/*            Sorts the Experimental Scientific Data                  */
/**********************************************************************/
void sort_data(int quantity, float *p_data)
{
   float *p_biggest,      /* Largest value in the array of data       */
         *p_data_counter, /* Loop control variable for the data       */
         *p_sort,         /* Array for the sorted data values         */
		 *p_sort_counter; /* Loop control variable for the sorted data*/
		 
   /* Allocates memory for experimental scientific data values and    */
   /* aborts if an error occurs	                                      */
   if((p_sort_counter = (float *) malloc(sizeof(*p_sort_counter) * 
      quantity)) == NULL)
   {
      printf("\nError %d occurred in sort function ", SORT_ALLOC_ERR);
      printf("\nCan't allocate memory for scientific data");
	  printf("\nThe program is aborting");
	  exit(SORT_ALLOC_ERR);
	}
	
	/* Sort the experimental scientific data in descending order      */
   for(p_sort = p_sort_counter; (p_sort - p_sort_counter) < quantity; 
   															   p_sort++)
   {
      *p_sort = 0.0f;
	  for(p_data_counter = p_data; (p_data_counter - p_data) < quantity; 
	  												   p_data_counter++)
      {
         if(*p_data_counter > *p_sort)
         {
            *p_sort   = *p_data_counter;
		 	p_biggest = p_data_counter;
         }
      }
      *p_biggest = 0.0f;
   }
	
   /* Copies the sorted experimental scientific data to memory        */
   memcpy(p_data, p_sort_counter, sizeof(*p_sort_counter) * quantity);
	 
   /* Frees allocated memory for experimental scientific data         */   
   free(p_sort_counter);
   
   return;
}

/**********************************************************************/
/*       Calculates the Sum of the Experimental Scientific Data       */
/**********************************************************************/
float calculate_sum(int quantity, float *p_data)
{
   float *p_data_counter, /* Loop control variable for the data       */
         data_sum = 0.0f; /* Sum of experimental scientific data      */
	      
   for(p_data_counter = p_data; (p_data_counter - p_data) < quantity; 
   													   p_data_counter++)
      data_sum += *p_data_counter;
	
	return data_sum;
}

/**********************************************************************/
/*          Prints the Experimental Scientific Data                   */
/**********************************************************************/
void print_data(int quantity, float *p_data)
{
   float *p_counter; /* Loop control variable                         */
	
   printf("\nThe data in descending order (with duplicates noted):");
   printf("\n-----------------------------------------------------");
	
   for(p_counter = p_data; (p_counter - p_data) < quantity; p_counter++)
   {
      if(*p_counter == *p_counter + 1)
	     printf("\n                 %9.2f (Duplicate)", *p_counter);
	  else
		 printf("\n                 %9.2f", *p_counter);
   } 
   return;
}

/**********************************************************************/
/*       Prints the Sum of Experimental Scientific Data Values        */
/**********************************************************************/
void print_sum(float data_sum)
{
   printf("\n                 ---------");
   printf("\n           %9.2f total", data_sum);
   return;
}
