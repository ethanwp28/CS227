/**********************************************************************/
/*																	                   */
/* Program Name:   program7 - */
/* Author:		    Ethan Pinto										          */
/* Installation:   Pensacola Christian College, Pensacola, Florida    */
/* Course:		    CS227, Data Structures and Algorithms			       */
/* Date Written:   November 23, 2016						    		       */
/*																	                   */
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
/* This program */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>
#include <stdbool.h>

/**********************************************************************/
/*                        Symbolic Constants                          */
/**********************************************************************/
#define PROGRAM_NUMBER  7       /* Teacher assigned program number    */
#define LAST_NAME       "Pinto" /* The programmer's last name         */  
#define COURSE_NUMBER   "CS227" /* PCC assigned course number         */
#define QUIT            0       /* Program's exit value               */
#define DATA_SIZE       15      /* Amount of data in the array        */
#define MAX_INDEX       14      /* Size of the array index            */

/**********************************************************************/
/*                       Function Prototypes                          */
/**********************************************************************/
void print_heading();
   /* Prints the program heading                                      */
void print_instructions();
   /* Prints the program instructions                                 */
void fill_array();
   /*  */
void show_search_info();
   /*  */
void print_search_results();
   /*  */
bool ordered_sequential_search();
   /*  */
bool probability_search();
   /*   */
bool binary_search();
   /*   */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
	int seq_data[MAX_INDEX], /* Ordered sequential search data         */
		 prb_data[MAX_INDEX], /* Probability search data                */
		 bin_data[MAX_INDEX], /* Binary search data                     */
		 search_target,
		 last_index,
		 address;
		 
	/* Prints the program heading and instructions                     */
   printf("\n\n\n\n\n\n\n");
   print_heading();
   print_instructions();
   
   /* Fill an array with ordered sequential whole numbers             */
   fill_array();
   
   /* Loop processing user target numbers until the user quits        */
   while(printf("\n\nEnter search target (0 to quit): "), 
	   scanf("%d", &search_target), search_target != 0)
   {
	
   	/* Ordered sequential search                                    */
   	printf("\n\nOrdered Sequential Search:");
   	show_search_info(search_target);
   	if (ordered_sequential_search(seq_data[MAX_INDEX], search_target, last_index, address))
   	   print_search_results('S', search_target);
   	else
   	   print_search_results('U', search_target);
   	   
   	/* Probabiility search                                          */
   	printf("\n\nProbability Search:");
   	show_search_info(search_target);
   	if (probability_search(prb_data[MAX_INDEX], search_target, last_index, address))
   	   print_search_results('S', search_target);
   	else
   	   print_search_results('U', search_target);
   	   
   	/* Binary search                                                */
   	printf("\n\nBinary Search:");
   	show_search_info(search_target);
   	if (binary_search(bin_data[MAX_INDEX], search_target, last_index, address))
   	   print_search_results('S', search_target);
   	else
   	   print_search_results('U', search_target);
   }	
   
   /* Print a goodbye message and terminate the program                */
   printf("\n\nThanks for searching.  Have a nice day! ;-)");
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
	printf("\nThis program demonstrates various search algorithms.");
	printf("\nYou enter in any whole number, and the program will");
	printf("\nsearch for in in an ORDERED array of whole numbers");
	printf("\nusing each of the following search algorithms:");
	printf("\n     1. Ordered Sequential Search");
	printf("\n     2. Probability Search");
	printf("\n     3. Binary search");
	printf("\nThe progress of each search is shown so the efficiency");
	printf("\nof the search algorithms can be compared");
}

/**********************************************************************/
/*             Fill the Array  with Ordered Whole Numbers             */
/**********************************************************************/
void fill_array()
{

}

/**********************************************************************/

/**********************************************************************/
void show_search_info(int search_target)
{
	int current_index,
	    array_data;
	
	printf("\n   Array Index: ");
	for(current_index = 0; current_index <= MAX_INDEX; current_index++)
	   printf("[%2d]", current_index);
	printf("\n   Array Data: ");
	for(array_data = 0; array_data < DATA_SIZE; array_data++)
	{
		array_data = array_data + 5;
		printf("   %d", array_data);
	}
	printf("\n   User Target: %d", search_target);
	return;
}

/**********************************************************************/

/**********************************************************************/
void print_search_results(int result, int target_index)
{
	if(result == 'S')
	{	
		printf("\nSearch Outcome: Successful - target found at index [%2d]", target_index);
		if (result == 'U')
		   printf("\nSearch Outcome: Unsuccessful - target not found");
	}
	else
		printf("\nSearch Outcome: Undetermined - ");

	return;
}

/**********************************************************************/

/**********************************************************************/
bool ordered_sequential_search(int seq_data[MAX_INDEX], int search_target, 
                               int last_index, int* p_address)
{
  /* int looker = 0;

   while (looker < last_index && search_target != seq_data[looker])
         looker++;

   *p_address = looker; 
   return (search_target == seq_data[looker]); */
}

/**********************************************************************/

/**********************************************************************/
bool probability_search(int prb_data[MAX_INDEX], int last_index,
                        int search_target, int* p_address)
{
/*	int found = 0;
   if(search_target = prb_data[MAX_INDEX])
      found = TRUE;
      *p_address = prb_data[];
      if(search_target + 1)
      *p_address + 1;
   else
      found = FALSE;
   return found; */

}

/**********************************************************************/

/**********************************************************************/
bool binary_search(int bin_data[MAX_INDEX], int last_index, int search_target,
                   int* p_address)
{
 	/*int begin = 0,
       middle,
       end;

   end = last_index;
   while (begin <= end)
   {
      middle = (begin + end) / 2;
      if (search_target > bin_data[middle])
         begin = middle + 1;
      else if (search_target < bin_data[middle])
         end = middle - 1;
      else
         begin = end + 1;
   }
   *p_address = middle;
   return (search_target == bin_data[middle]); */
}
