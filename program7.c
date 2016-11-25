/**********************************************************************/
/*																	                   */
/* Program Name:   program7 - Searching an Ordered Array of Whole     */
/*                            Numbers                                 */
/* Author:	   Ethan Pinto				              */
/* Installation:   Pensacola Christian College, Pensacola, Florida    */
/* Course:	   CS227, Data Structures and Algorithms              */
/* Date Written:   November 23, 2016				      */
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
/* This program fills an array with ordered sequential whole numbers  */
/* and then performs three search functions: ordered sequential,      */
/* probability, and binary.                                           */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>

/**********************************************************************/
/*                        Symbolic Constants                          */
/**********************************************************************/
#define PROGRAM_NUMBER  7       /* Teacher assigned program number    */
#define LAST_NAME       "Pinto" /* The programmer's last name         */  
#define COURSE_NUMBER   "CS227" /* PCC assigned course number         */
#define QUIT            0       /* Program's exit value               */
#define DATA_SIZE       15      /* Amount of data in the array        */
#define MAX_INDEX       DATA_SIZE - 1
                                /* Size of the array index            */

/**********************************************************************/
/*                       Function Prototypes                          */
/**********************************************************************/
void print_heading();
   /* Prints the program heading                                      */
void print_instructions();
   /* Prints the program instructions                                 */
void fill_array(int search_data[]);
   /* Fills the array with ordered sequential whole numbers           */
void show_search_info(int search_target, int search_data[]);
   /* Displays the search information                                 */
void print_search_results(int result, int target_index);
   /* Prints the results of the searches                              */
int ordered_sequential_search(int seq_data[], int search_target, 
                              int last_index, int* p_address);
   /* Ordered sequential search in the whole number array             */
int probability_search(int prb_data[], int last_index,
                       int search_target, int* p_address);
   /* Probability search in the whole number array                    */
int binary_search(int bin_data[], int last_index, int search_target,
                  int* p_search_target);
   /* Binary search in the whole number array                         */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
	int seq_data[DATA_SIZE], /* Ordered sequential search data         */
		 prb_data[DATA_SIZE], /* Probability search data                */
		 bin_data[DATA_SIZE], /* Binary search data                     */
		 search_index = 0,    /* Index of every whole number            */
       search_target;       /* Target value for the search algorithm  */
		 
	/* Print the program heading and instructions                      */
   printf("\n\n\n\n\n\n\n");
   print_heading();
   print_instructions();
   
   /* Fill an array with ordered sequential whole numbers             */
   fill_array(seq_data); 
   fill_array(prb_data); 
   fill_array(bin_data);

   /* Loop processing user target numbers until the user quits        */
   while(printf("\n\n\nEnter an integer search target (0 to quit): "), 
	   scanf("%d", &search_target), search_target != 0)
   {
	
   	/* Display the search information, perform an ordered           */
   	/* sequential search on the ordered array of whole numbers, and */
   	/* print the results of the search                              */
   	printf("\n\nOrdered Sequential Search:");
   	show_search_info(search_target, seq_data);
   	if(ordered_sequential_search(seq_data, search_target, 
         MAX_INDEX, &search_index))
   	   print_search_results('S', search_index);
   	else
   	   print_search_results('U', search_index);
   	   
   	/* Display the search information, perform a probability search */
		/* on the ordered array of whole numbers, and print the results */
		/* of the search                                                */
   	printf("\n\nProbability Search:");
   	show_search_info(search_target, prb_data);
   	if(probability_search(prb_data, MAX_INDEX, 
         search_target, &search_index))
   	   print_search_results('S', search_index);
   	else
   	   print_search_results('U', search_index);
   	   
    	/* Display the search information, perform a binary search on   */
		/* the ordered array of whole numbers, and print the results of */
		/* the search                                                   */
   	printf("\n\nBinary Search:");
   	show_search_info(search_target, bin_data);
   	if(binary_search(bin_data, search_target, 
         MAX_INDEX, &search_index))
   	   print_search_results('S', search_index);
   	else
   	   print_search_results('U', search_index);
   }	
   
   /* Print a goodbye message and terminate the program               */
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
	printf("\nsearch for it in an ORDERED array of whole numbers");
	printf("\nusing each of the following search algorithms:");
	printf("\n     1. Ordered Sequential Search");
	printf("\n     2. Probability Search");
	printf("\n     3. Binary Search");
	printf("\nThe progress of each search is shown so the efficiency");
	printf("\nof the search algorithms can be compared.");
}

/**********************************************************************/
/*             Fill the Array with Ordered Whole Numbers              */
/**********************************************************************/
void fill_array(int search_data[])
{
	int index = 0; /* Index of every whole number                      */
	
   for(index = 0; index < DATA_SIZE; index++)
      search_data[index] = (index * 5) + 10;
      
   return;
}

/**********************************************************************/
/*              Display the Search Information within the             */
/**********************************************************************/
void show_search_info(int search_target, int search_data[])
{
	int current_index; /* Index of every whole number                  */
	
	printf("\n   Array Index: "); 
   for(current_index = 0; current_index <= MAX_INDEX; current_index++)
      printf("[%2d]", current_index);

   printf("\n    Array Data: ");
	for(current_index = 0; current_index <= MAX_INDEX; current_index++)
   {
      search_data[current_index] = (current_index * 5) + 10;
	   printf(" %d ", search_data[current_index]);
   }
	printf("\n   User Target:  %d", search_target);
	return;
}

/**********************************************************************/
/*                 Print the Results of the Searches                  */
/**********************************************************************/
void print_search_results(int result, int target_index)
{
	if(result == 'S' || 'U')	
	{
		if(result == 'S')
		printf("\nSearch Outcome: Successful - target found at index [%2d]",
         target_index);
      else
			printf("\nSearch Outcome: Unsuccessful - target not found");		
	}    
	else
	   printf("\nSearch Outcome: Undetermined ");
	   
	return;
}

/**********************************************************************/
/*  Ordered Sequential search in the Ordered Array of Whole Numbers   */
/**********************************************************************/
int ordered_sequential_search(int seq_data[], int search_target, 
                              int last_index, int* p_search_target)
{
   int search_index = 0; /* Index of every whole number               */
   
   printf("\n   Search Path: ");
   while (search_index <= MAX_INDEX && 
      search_target != seq_data[search_index])                                                          
   {      
      *p_search_target = search_index; 
      printf("[%2d]", search_index);
      search_index++;
   }
   if (search_target == seq_data[search_index])
   {
      *p_search_target = search_index;
      printf("[%2d]", search_index);
   }
   return (search_target == seq_data[search_index]); 
}

/**********************************************************************/
/*      Probability Search in the Ordered Array of Whole Numbers      */
/**********************************************************************/
int probability_search(int prb_data[], int last_index,
                       int search_target, int* p_search_target)
{
   int search_index = 0, /* Index of every whole number               */
       temp_index;       /* Temporary index for the swap              */

   printf("\n   Search Path: ");
   while(search_index <= last_index && 
      search_target != prb_data[search_index])
   {
      printf("[%2d]", search_index);
		search_index++; 
   }
	printf("[%2d]", search_index);
   if(search_target == prb_data[search_index])
   {
      if(search_index > 1)
      {
         temp_index                  = prb_data[search_index - 1];
         prb_data[search_index - 1]  = prb_data[search_index];
         prb_data[search_index]      = temp_index;
         search_index               -= 1;
      }
   }
   else
      search_index--;
	*p_search_target = search_index + 1;
   return (search_target == prb_data[search_index]);
}

/**********************************************************************/
/*        Binary Search in the Ordered Array of Whole Numbers         */
/**********************************************************************/
int binary_search(int bin_data[], int search_target, int last_index,
                  int* p_search_target)
{
 	int begin_index = 0, /* Index of the beginning of the data         */
       middle_index,    /* Index searching for the target value       */
       end_index;       /* Index of the enx of the data               */

   end_index = MAX_INDEX;
   printf("\n   Search Path: ");
   while (begin_index <= end_index)
   {
      middle_index = (begin_index + end_index) / 2;
      if (search_target > bin_data[middle_index])
      {
         begin_index = middle_index + 1;
         printf("[%2d]", middle_index);
      }
      else 
      {
         if (search_target < bin_data[middle_index])
         {
            end_index = middle_index - 1;
            printf("[%2d]", middle_index);
         }
         else
         {
            begin_index = end_index + 1;
            printf("[%2d]", middle_index);
         }
      }
   }
   *p_search_target = middle_index;
   return(search_target == bin_data[middle_index]); 
}
